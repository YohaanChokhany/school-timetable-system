#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>

#include "database.h"
#include "studentlist.h"
#include "studentmodel.h"
#include "teacherlist.h"
#include "teachermodel.h"
#include "subjectlist.h"
#include "subjectmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Database>("database", 1, 0, "Database");
    qmlRegisterType<StudentModel>("Student", 1, 0, "StudentModel");
    qmlRegisterUncreatableType<StudentList>("Student", 1, 0, "StudentList", QStringLiteral("StudentList should not be created in QML"));
    qmlRegisterType<TeacherModel>("Teacher", 1, 0, "TeacherModel");
    qmlRegisterUncreatableType<TeacherList>("Teacher", 1, 0, "TeacherList", QStringLiteral("TeacherList should not be created in QML"));
    qmlRegisterType<SubjectModel>("Subject", 1, 0, "SubjectModel");
    qmlRegisterUncreatableType<SubjectList>("Subject", 1, 0, "SubjectList", QStringLiteral("SubjectList should not be created in QML"));

    QSqlDatabase::addDatabase("QSQLITE").setDatabaseName("../Databases/db.sqlite");

    StudentList list11(nullptr, 11);
    StudentList list12(nullptr, 12);

    TeacherList teachers;
    SubjectList subjects;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("list11"), &list11);
    engine.rootContext()->setContextProperty(QStringLiteral("list12"), &list12);
    engine.rootContext()->setContextProperty(QStringLiteral("teacherList"), &teachers);
    engine.rootContext()->setContextProperty(QStringLiteral("subjectList"), &subjects);

    const QUrl url(u"qrc:/IA/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
