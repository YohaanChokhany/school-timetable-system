#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QObject>
#include <QVector>
#include <QSqlQuery>
#include <QFuture>
#include <QtConcurrent>

#include "global.h"

struct Student
{
    int reg;
    QString edu;
    QString name;
    QString first_name;
    QString middle_name;
    QString last_name;
    QString gender;
    QString hl1;
    QString hl2;
    QString hl3;
    QString sl1;
    QString sl2;
    QString sl3;
    QList<int> subjects;
    QMap<QString, QString> classes;
};

class StudentList : public QObject
{
    Q_OBJECT
public:
    explicit StudentList(QObject *parent = nullptr, int grade = 11);

    QVector<Student> items() const;

    bool setItemAt(int index, const Student &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(int reg, QString edu, QString name, QString first_name, QString middle_name, QString last_name, QString gender, QString hl1, QString hl2, QString hl3, QString sl1, QString sl2, QString sl3, QString block_1, QString block_2, QString block_3, QString block_4, QString block_5, QString block_6, QString block_7, QString block_8);
    void clearItems();
    void removeStudents(QList<int> students);
    void searchStudents(QString query);
    void loadStudents();
    QStringList getStudent(QList<int> student);

private:
    QVector<Student> mItems;
    QSqlDatabase db;
    int mGrade;
};

#endif // STUDENTLIST_H
