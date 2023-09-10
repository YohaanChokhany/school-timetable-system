#ifndef SUBJECTMODEL_H
#define SUBJECTMODEL_H

#include <QAbstractListModel>

Q_MOC_INCLUDE("subjectlist.h")

class SubjectList;

class SubjectModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(SubjectList *list READ list WRITE setList)

public:
    explicit SubjectModel(QObject *parent = nullptr);

    enum {
        IDRole = Qt::UserRole,
        CodeRole,
        NameRole,
        TeachersRole,
        BatchesRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    SubjectList *list() const;
    void setList(SubjectList *list);

private:
    SubjectList *mList;
};

#endif // SUBJECTMODEL_H
