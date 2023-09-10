#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QAbstractListModel>

Q_MOC_INCLUDE("studentlist.h")

class StudentList;

class StudentModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(StudentList *list READ list WRITE setList)
    Q_PROPERTY(int *grade READ grade WRITE setGrade)

public:
    explicit StudentModel(QObject *parent = nullptr);

    enum {
        RegRole = Qt::UserRole,
        EduRole,
        NameRole,
        FirstNameRole,
        MiddleNameRole,
        LastNameRole,
        GenderRole,
        HL1Role,
        HL2Role,
        HL3Role,
        SL1Role,
        SL2Role,
        SL3Role,
        SubjectsRole,
        ClassesRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    StudentList *list() const;
    void setList(StudentList *list);

    int *grade() const;
    void setGrade(int *grade);

private:
    StudentList *mList;
    int *mGrade;
};

#endif // STUDENTMODEL_H
