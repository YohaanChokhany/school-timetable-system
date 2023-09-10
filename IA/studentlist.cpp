#include "studentlist.h"

using namespace QtConcurrent;

StudentList::StudentList(QObject *parent, int grade) : QObject(parent)
{
    db = QSqlDatabase::database();
    mGrade = grade;
    loadStudents();
}

QVector<Student> StudentList::items() const
{
    return mItems;
}

void StudentList::clearItems()
{
    for (int i = 0; i < mItems.size(); ) {
        emit preItemRemoved(i);
        mItems.removeAt(i);
        emit postItemRemoved();
    }
}

void StudentList::loadStudents()
{
    clearItems();

    QSqlQuery query("SELECT * from students WHERE grade = " + QVariant(mGrade).toString());

    while(query.next()) {
        QString name = query.value(2).toString() + " " + query.value(4).toString();
        if (query.value(3).toString() != "") {
            name = query.value(2).toString() + " " + query.value(3).toString() + " " + query.value(4).toString();
        }

        appendItem(
            query.value(0).toInt(),
            query.value(1).toString(),
            name,
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            global().code_to_subject[query.value(7).toInt()],
            global().code_to_subject[query.value(8).toInt()],
            global().code_to_subject[query.value(9).toInt()],
            global().code_to_subject[query.value(10).toInt()],
            global().code_to_subject[query.value(11).toInt()],
            global().code_to_subject[query.value(12).toInt()],
            query.value(13).toString(),
            query.value(14).toString(),
            query.value(15).toString(),
            query.value(16).toString(),
            query.value(17).toString(),
            query.value(18).toString(),
            query.value(19).toString(),
            query.value(20).toString()
        );
    }
}

QStringList StudentList::getStudent(QList<int> student)
{
    Student studentData = mItems[student[0]];
    QString gender = studentData.gender == "M" ? "Male" : "Female";
    return { QVariant(studentData.reg).toString(), studentData.edu, studentData.first_name, studentData.middle_name, studentData.last_name, gender, studentData.hl1.replace("&", "and"), studentData.hl2.replace("&", "and"), studentData.hl3.replace("&", "and"), studentData.sl1.replace("&", "and"), studentData.sl2.replace("&", "and"), studentData.sl3.replace("&", "and") };
}

bool StudentList::setItemAt(int index, const Student &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const Student &oldItem = mItems.at(index);

    if (item.reg == oldItem.reg && item.edu == oldItem.edu && item.first_name == oldItem.first_name && item.middle_name == oldItem.middle_name && item.last_name == oldItem.last_name && item.gender == oldItem.gender && item.hl1 == oldItem.hl1 && item.hl2 == oldItem.hl2 && item.hl3 == oldItem.hl3 && item.sl1 == oldItem.sl1 && item.sl2 == oldItem.sl2 && item.sl3 == oldItem.sl3 && item.classes == oldItem.classes)
        return false;

    QSqlQuery query("UPDATE students SET first_name = '" + item.first_name + "', middle_name = '" + item.middle_name + "', last_name = '" + item.last_name + "', edu = '" + item.edu + "', gender = '" + item.gender + "', "
               "hl_subject_1 = " + QVariant(global().subject_to_code[item.hl1]).toString() + ", hl_subject_2 = " + QVariant(global().subject_to_code[item.hl2]).toString() + ", hl_subject_3 = " + QVariant(global().subject_to_code[item.hl3]).toString() + ", "
               "sl_subject_1 = " + QVariant(global().subject_to_code[item.sl1]).toString() + ", sl_subject_2 = " + QVariant(global().subject_to_code[item.sl2]).toString() + ", sl_subject_3 = " + QVariant(global().subject_to_code[item.sl3]).toString() + " "
               "WHERE reg = " + QVariant(item.reg).toString());

    mItems[index] = item;
    return true;
}

void StudentList::appendItem(int reg, QString edu, QString name, QString first_name, QString middle_name, QString last_name, QString gender, QString hl1, QString hl2, QString hl3, QString sl1, QString sl2, QString sl3, QString block_1, QString block_2, QString block_3, QString block_4, QString block_5, QString block_6, QString block_7, QString block_8)
{
    emit preItemAppended();

    Student item;
    item.reg = reg;
    item.edu = edu;
    item.name = name;
    item.first_name = first_name;
    item.middle_name = middle_name;
    item.last_name = last_name;
    item.gender = gender;
    item.hl1 = hl1;
    item.hl2 = hl2;
    item.hl3 = hl3;
    item.sl1 = sl1;
    item.sl2 = sl2;
    item.sl3 = sl3;
    item.classes.insert("block_1", block_1);
    item.classes.insert("block_2", block_2);
    item.classes.insert("block_3", block_3);
    item.classes.insert("block_4", block_4);
    item.classes.insert("block_5", block_5);
    item.classes.insert("block_6", block_6);
    item.classes.insert("block_7", block_7);
    item.classes.insert("block_8", block_8);

    mItems.append(item);

    emit postItemAppended();
}

void StudentList::removeStudents(QList<int> students)
{
    for (int student : students) {
        qDebug() << mItems[student].name;
        QSqlQuery query("DELETE FROM students WHERE reg = " + QVariant(mItems[student].reg).toString());
    }

    loadStudents();
}

void StudentList::searchStudents(QString query)
{
    query = query.toLower();

    loadStudents();
    for (int i = 0; i < mItems.size(); ) {
        QString gender = mItems[i].gender == "M" ? "male" : "female";
        QString mediumName = (mItems[i].first_name + " " + mItems[i].last_name).toLower();

        if (!QVariant(mItems[i].reg).toString().contains(query) && !mItems[i].name.toLower().contains(query) && !mediumName.contains(query) && !mItems[i].edu.toLower().contains(query) && gender != query && !mItems[i].hl1.toLower().contains(query) && !mItems[i].hl2.toLower().contains(query) && !mItems[i].hl3.toLower().contains(query) && !mItems[i].sl1.toLower().contains(query) && !mItems[i].sl2.toLower().contains(query) && !mItems[i].sl3.toLower().contains(query)) {
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();
        } else {
            ++i;
        }
    }
}
