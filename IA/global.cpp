#include "global.h"

global::global(QObject *parent)
    : QObject{parent}
{
    QSqlQuery query("SELECT * FROM subjects");
    while (query.next()) {
        code_to_subject[query.value(0).toInt()] = query.value(2).toString();
        subject_to_code[query.value(2).toString()] = query.value(0).toInt();

        id_to_code[query.value(0).toInt()] = query.value(1).toString();
        code_to_id[query.value(1).toString()] = query.value(0).toInt();
    }

    query.exec("SELECT * FROM teachers");
    while (query.next()) {
        code_to_teacher[query.value(0).toInt()] = query.value(1).toString();
        teacher_to_code[query.value(1).toString()] = query.value(0).toInt();
    }

    query.exec("SELECT * FROM locations");
    while (query.next()) {
        code_to_location[query.value(0).toInt()] = query.value(1).toString();
        location_to_code[query.value(1).toString()] = query.value(0).toInt();
    }
}
