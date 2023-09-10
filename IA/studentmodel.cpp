#include "studentmodel.h"
#include "studentlist.h"

StudentModel::StudentModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
    , mGrade(nullptr)
{
}

int StudentModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant StudentModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const Student &item = mList->items().at(index.row());
    QStringList subjects;
    for (int subject : item.subjects) {
        subjects.append(QVariant(subject).toString());
    }
    switch (role) {
    case RegRole:
        return QVariant(item.reg);
    case EduRole:
        return QVariant(item.edu);
    case NameRole:
        return QVariant(item.name);
    case FirstNameRole:
        return QVariant(item.first_name);
    case MiddleNameRole:
        return QVariant(item.middle_name);
    case LastNameRole:
        return QVariant(item.last_name);
    case GenderRole:
        return QVariant(item.gender);
    case HL1Role:
        return QVariant(item.hl1);
    case HL2Role:
        return QVariant(item.hl2);
    case HL3Role:
        return QVariant(item.hl3);
    case SL1Role:
        return QVariant(item.sl1);
    case SL2Role:
        return QVariant(item.sl2);
    case SL3Role:
        return QVariant(item.sl3);
    case SubjectsRole:
        return QVariant(subjects);
    case ClassesRole:
        return QVariant(item.classes.values());
    }

    return QVariant();
}

bool StudentModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    Student item = mList->items().at(index.row());
    switch (role) {
    case RegRole:
        item.reg = value.toInt();
        break;
    case EduRole:
        item.edu = value.toString();
        break;
    case FirstNameRole:
        item.first_name = value.toString();
        break;
    case MiddleNameRole:
        item.middle_name = value.toString();
        break;
    case LastNameRole:
        item.last_name = value.toString();
        break;
    case GenderRole:
        item.gender = value.toString();
        break;
    case HL1Role:
        item.hl1 = value.toString();
        break;
    case HL2Role:
        item.hl2 = value.toString();
        break;
    case HL3Role:
        item.hl3 = value.toString();
        break;
    case SL1Role:
        item.sl1 = value.toString();
        break;
    case SL2Role:
        item.sl2 = value.toString();
        break;
    case SL3Role:
        item.sl3 = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags StudentModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> StudentModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[RegRole] = "reg";
    names[EduRole] = "edu";
    names[NameRole] = "name";
    names[FirstNameRole] = "first_name";
    names[MiddleNameRole] = "middle_name";
    names[LastNameRole] = "last_name";
    names[GenderRole] = "gender";
    names[HL1Role] = "hl1";
    names[HL2Role] = "hl2";
    names[HL3Role] = "hl3";
    names[SL1Role] = "sl1";
    names[SL2Role] = "sl2";
    names[SL3Role] = "sl3";
    names[SubjectsRole] = "subjects";
    names[ClassesRole] = "classes";
    return names;
}

StudentList *StudentModel::list() const
{
    return mList;
}

void StudentModel::setList(StudentList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &StudentList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &StudentList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &StudentList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &StudentList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}

int *StudentModel::grade() const
{
    return mGrade;
}

void StudentModel::setGrade(int *grade)
{
    mGrade = grade;
}
