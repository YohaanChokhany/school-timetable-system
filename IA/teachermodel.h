#ifndef TEACHERMODEL_H
#define TEACHERMODEL_H

#include <QAbstractListModel>

Q_MOC_INCLUDE("teacherlist.h")

class TeacherList;

class TeacherModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(TeacherList *list READ list WRITE setList)

public:
    explicit TeacherModel(QObject *parent = nullptr);

    enum {
        IDRole = Qt::UserRole,
        NameRole,
        SubjectsRole,
        Block1Role,
        Block2Role,
        Block3Role,
        Block4Role,
        Block5Role,
        Block6Role,
        Block7Role
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    TeacherList *list() const;
    void setList(TeacherList *list);

private:
    TeacherList *mList;
};

#endif // TEACHERMODEL_H
