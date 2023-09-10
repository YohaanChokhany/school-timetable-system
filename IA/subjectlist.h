#ifndef SUBJECTLIST_H
#define SUBJECTLIST_H

#include <QObject>
#include <QVector>
#include <QSqlQuery>

#include "global.h"

struct Subject
{
    int id;
    QString code;
    QString name;
    QStringList teachers;
    QStringList batches;
};

class SubjectList : public QObject
{
    Q_OBJECT
public:
    explicit SubjectList(QObject *parent = nullptr);

    QVector<Subject> items() const;

    bool setItemAt(int index, const Subject &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendSubject(int id, QString code, QString name, QString teachers, QString batches);
    void clearSubjects();
    void removeSubjects(QList<int> subjects);
    void searchSubjects(QString query);
    void loadSubjects();
    QStringList getSubject(QList<int> subject);

private:
    QVector<Subject> mItems;
    QSqlDatabase db;
    int mGrade;
};

#endif // SUBJECTLIST_H
