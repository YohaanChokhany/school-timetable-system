#include "subjectmodel.h"
#include "subjectlist.h"

SubjectModel::SubjectModel(QObject *parent)
    : QAbstractListModel{parent}
    , mList(nullptr)
{
}

int SubjectModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant SubjectModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    QString teachers = "";
    QString batches = "";
    const Subject &subject = mList->items().at(index.row());

    switch(role) {
    case IDRole:
        return QVariant(subject.id);
    case CodeRole:
        return QVariant(subject.code);
    case NameRole:
        return QVariant(subject.name);
    case TeachersRole:
        for (QString teacher : subject.teachers) {
            teachers.append(global().code_to_teacher[teacher.toInt()] + ", ");
        }
        return teachers.mid(0, teachers.length() - 2);
    }

    return QVariant();
}

bool SubjectModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    Subject subject = mList->items().at(index.row());
    switch (role) {
    case IDRole:
        subject.id = value.toInt();
    case CodeRole:
        subject.code = value.toString();
    case NameRole:
        subject.name = value.toString();
    case TeachersRole:
        subject.teachers = value.toString().split(", ");
    }

    if (mList->setItemAt(index.row(), subject)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags SubjectModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> SubjectModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IDRole] = "id";
    names[NameRole] = "name";
    names[CodeRole] = "code";
    names[TeachersRole] = "teachers";
    names[BatchesRole] = "batches";
    return names;
}

SubjectList *SubjectModel::list() const
{
    return mList;
}

void SubjectModel::setList(SubjectList *list)
{
    beginResetModel();
    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &SubjectList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &SubjectList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &SubjectList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &SubjectList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
