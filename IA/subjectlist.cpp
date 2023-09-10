#include "subjectlist.h"

SubjectList::SubjectList(QObject *parent)
    : QObject{parent}
{

}

QVector<Subject> SubjectList::items() const
{
    return mItems;
}

void SubjectList::clearSubjects()
{
    for (int i = 0; i < mItems.size(); ) {
        emit preItemRemoved(i);
        mItems.removeAt(i);
        emit postItemRemoved();
    }
}

void SubjectList::loadSubjects()
{
    clearSubjects();

    QSqlQuery query("SELECT * FROM subjects");

    while (query.next()) {
        appendSubject(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString()
        );
    }
}

QStringList SubjectList::getSubject(QList<int> subject)
{
    Subject subjectData = mItems[subject[0]];
    QString teachers = "";
    QString batches = "";

    for (QString teacher : subjectData.teachers) {
        teachers.append(teacher + ", ");
    }
    for (QString batch : subjectData.batches) {
        batches.append(batch + ", ");
    }

    return { QVariant(subjectData.id).toString(), subjectData.code, subjectData.name, teachers.mid(0, teachers.length() - 2), batches.mid(0, batches.length() - 2) };
}

bool SubjectList::setItemAt(int index, const Subject &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const Subject &oldItem = mItems.at(index);

    if (item.name == oldItem.name && item.code == oldItem.code && item.teachers == oldItem.teachers && item.batches == oldItem.batches)
        return false;

    QSqlQuery query("UPDATE subjects SET name = '" + item.name + "', code = '" + item.code + "' WHERE id = " + QVariant(item.id).toString());

    mItems[index] = item;
    return true;
}

void SubjectList::appendSubject(int id, QString code, QString name, QString teachers, QString batches)
{
    emit preItemAppended();

    Subject subject;
    subject.id = id;
    subject.code = code;
    subject.name = name;
    subject.teachers = teachers.split(", ");
    subject.batches = batches.split(", ");

    mItems.append(subject);

    emit postItemAppended();
}

void SubjectList::removeSubjects(QList<int> subjects)
{
    for (int subject : subjects) {
        QSqlQuery query("DELETE FROM subjects WHERE id = " + mItems[subject].id);
    }

    loadSubjects();
}

void SubjectList::searchSubjects(QString query)
{
    query = query.toLower().trimmed();

    loadSubjects();
    for (int i = 0; i < mItems.size(); ) {
        QString teacher_str = "";
        for (QString teacher : mItems[i].teachers)
            teacher_str.append(global().code_to_teacher[QVariant(teacher).toInt()] + ", ");
        if (!mItems[i].code.toLower().contains(query) && !mItems[i].name.toLower().contains(query) && !teacher_str.toLower().mid(0, teacher_str.length() - 2).contains(query)) {
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();
        } else {
            ++i;
        }
    }
}
