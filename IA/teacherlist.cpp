#include "teacherlist.h"

TeacherList::TeacherList(QObject *parent)
    : QObject{parent}
{

}

QVector<Teacher> TeacherList::items() const
{
    return mItems;
}

void TeacherList::clearTeachers()
{
    for (int i = 0; i < mItems.size(); ) {
        emit preItemRemoved(i);
        mItems.removeAt(i);
        emit postItemRemoved();
    }
}

void TeacherList::loadTeachers()
{
    clearTeachers();

    QSqlQuery query("SELECT * FROM teachers");

    while (query.next()) {
        appendTeacher(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toString(),
            query.value(7).toString(),
            query.value(8).toString(),
            query.value(9).toString()
        );
    }
}

QStringList TeacherList::getTeacher(QList<int> teacher)
{
    Teacher teacherData = mItems[teacher[0]];
    QString subjects = "";

    for (QString subject : teacherData.subjects) {
        subjects.append(subject + ", ");
    }

    return { QVariant(teacherData.id).toString(), teacherData.name, subjects.mid(0, subjects.length() - 2), teacherData.block_1, teacherData.block_2, teacherData.block_3, teacherData.block_4, teacherData.block_5, teacherData.block_6, teacherData.block_7 };
}

bool TeacherList::setItemAt(int index, const Teacher &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const Teacher &oldItem = mItems.at(index);

    if (item.name == oldItem.name && item.subjects == oldItem.subjects && item.block_1 == oldItem.block_1 && item.block_2 == oldItem.block_2 && item.block_3 == oldItem.block_3 && item.block_4 == oldItem.block_4 && item.block_5 == oldItem.block_5 && item.block_6 == oldItem.block_6 && item.block_7 == oldItem.block_6)
        return false;

    QSqlQuery query("UPDATE students SET name = '" + item.name + "', "
               "block_1 = '" + item.block_1 + "', block_2 = '" + item.block_2 + "', block_3 = '" + item.block_3 + "', "
               "block_4 = '" + item.block_4 + "', block_5 = '" + item.block_5 + "', block_6 = '" + item.block_6 + "', "
               "block_7 = '" + item.block_7 + "' "
               "WHERE reg = " + QVariant(item.id).toString());

    mItems[index] = item;
    return true;
}

void TeacherList::appendTeacher(int id, QString name, QString subjects, QString block_1, QString block_2, QString block_3, QString block_4, QString block_5, QString block_6, QString block_7)
{
    emit preItemAppended();

    Teacher item;
    item.id = id;
    item.name = name;
    item.subjects = subjects.split(", ");
    item.block_1 = block_1;
    item.block_2 = block_2;
    item.block_3 = block_3;
    item.block_4 = block_4;
    item.block_5 = block_5;
    item.block_6 = block_6;
    item.block_7 = block_7;

    mItems.append(item);

    emit postItemAppended();
}

void TeacherList::removeTeachers(QList<int> teachers)
{
    for (int teacher : teachers) {
        QSqlQuery query("DELETE FROM teachers WHERE id = " + mItems[teacher].id);
    }

    loadTeachers();
}

void TeacherList::searchTeachers(QString query)
{
    query = query.toLower().trimmed();

    loadTeachers();
    for (int i = 0; i < mItems.size(); ) {
        QString subject_str = "";
        for (QString subject : mItems[i].subjects)
            subject_str.append(global().code_to_subject[QVariant(subject).toInt()] + ", ");
        if (!mItems[i].name.toLower().contains(query) && !subject_str.toLower().mid(0, subject_str.length() - 2).contains(query) && !mItems[i].block_1.toLower().contains(query) && !mItems[i].block_2.toLower().contains(query) && !mItems[i].block_3.toLower().contains(query) && !mItems[i].block_4.toLower().contains(query) && !mItems[i].block_5.toLower().contains(query) && !mItems[i].block_6.toLower().contains(query) && !mItems[i].block_7.toLower().contains(query)) {
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();
        } else {
            ++i;
        }
    }
}
