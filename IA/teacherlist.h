#ifndef TEACHERLIST_H
#define TEACHERLIST_H

#include <QObject>
#include <QVector>
#include <QSqlQuery>

#include "global.h"

struct Teacher
{
    int id;
    QString name;
    QStringList subjects;
    QString block_1;
    QString block_2;
    QString block_3;
    QString block_4;
    QString block_5;
    QString block_6;
    QString block_7;
    QMap<QString, QString> blocks;
};

class TeacherList : public QObject
{
    Q_OBJECT
public:
    explicit TeacherList(QObject *parent = nullptr);

    QVector<Teacher> items() const;

    bool setItemAt(int index, const Teacher &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendTeacher(int id, QString name, QString subjects, QString block_1, QString block_2, QString block_3, QString block_4, QString block_5, QString block_6, QString block_7);
    void clearTeachers();
    void removeTeachers(QList<int> teachers);
    void searchTeachers(QString query);
    void loadTeachers();
    QStringList getTeacher(QList<int> teacher);

private:
    QVector<Teacher> mItems;
    QSqlDatabase db;
    int mGrade;
};

#endif // TEACHERLIST_H
