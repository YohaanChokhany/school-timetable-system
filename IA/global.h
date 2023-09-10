#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>

class global : public QObject
{
    Q_OBJECT
public:
    explicit global(QObject *parent = nullptr);

    QMap<int, QString> code_to_subject;
    QMap<QString, int> subject_to_code;

    QMap<int, QString> id_to_code;
    QMap<QString, int> code_to_id;

    QMap<int, QString> code_to_teacher;
    QMap<QString, int> teacher_to_code;

    QMap<int, QString> code_to_location;
    QMap<QString, int> location_to_code;

signals:

};

#endif // GLOBAL_H
