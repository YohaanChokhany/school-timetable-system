#include "teachermodel.h"
#include "teacherlist.h"

TeacherModel::TeacherModel(QObject *parent)
    : QAbstractListModel{parent}
    , mList(nullptr)
{
}

int TeacherModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant TeacherModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    QString subjects = "";
    const Teacher &teacher = mList->items().at(index.row());
    switch (role) {
    case IDRole:
        return QVariant(teacher.id);
    case NameRole:
        return QVariant(teacher.name);
    case SubjectsRole:
        for (QString subject : teacher.subjects) {
            subjects.append(global().code_to_subject[subject.toInt()] + ", ");
        }
        return subjects.mid(0, subjects.length() - 2);
    case Block1Role:
        return QVariant(teacher.block_1);
    case Block2Role:
        return QVariant(teacher.block_2);
    case Block3Role:
        return QVariant(teacher.block_3);
    case Block4Role:
        return QVariant(teacher.block_4);
    case Block5Role:
        return QVariant(teacher.block_5);
    case Block6Role:
        return QVariant(teacher.block_6);
    case Block7Role:
        return QVariant(teacher.block_7);
    }

    return QVariant();
}

bool TeacherModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    Teacher teacher = mList->items().at(index.row());
    switch (role) {
    case IDRole:
        teacher.id = value.toInt();
    case NameRole:
        teacher.name = value.toString();
    case SubjectsRole:
        teacher.subjects = value.toString().split(", ");
    case Block1Role:
        teacher.block_1 = value.toString();
    case Block2Role:
        teacher.block_2 = value.toString();
    case Block3Role:
        teacher.block_3 = value.toString();
    case Block4Role:
        teacher.block_4 = value.toString();
    case Block5Role:
        teacher.block_5 = value.toString();
    case Block6Role:
        teacher.block_6 = value.toString();
    case Block7Role:
        teacher.block_7 = value.toString();
    }

    if (mList->setItemAt(index.row(), teacher)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags TeacherModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> TeacherModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IDRole] = "id";
    names[NameRole] = "name";
    names[SubjectsRole] = "subjects";
    names[Block1Role] = "block_1";
    names[Block2Role] = "block_2";
    names[Block3Role] = "block_3";
    names[Block4Role] = "block_4";
    names[Block5Role] = "block_5";
    names[Block6Role] = "block_6";
    names[Block7Role] = "block_7";
    return names;
}

TeacherList *TeacherModel::list() const
{
    return mList;
}

void TeacherModel::setList(TeacherList *list)
{
    beginResetModel();
    if(mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &TeacherList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &TeacherList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &TeacherList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &TeacherList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
