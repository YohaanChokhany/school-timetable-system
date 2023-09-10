#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QCryptographicHash>
#include <QRegularExpression>
#include <QRandomGenerator>
#include <QFuture>
#include <QtConcurrent>
#include <QTextDocument>
#include <QPrinter>
#include <QPageLayout>

#include "global.h"
#include "studentlist.h"
#include "teacherlist.h"
#include "subjectlist.h"

struct Batch
{
    QString id;
    int subject;
    QString level;
    int block;
    int teacher;
    int grade;
    QList<int> students;
};

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

    QList<Batch> optimum_batches;

signals:
    void progress(int progress, int epochs);
    void downloadProgress(int progress, int total);

public slots:
    QStringList getSubjects();
    QStringList getStudents(QString search_query);
    QString loginUser(QString username, QString password);
    QString addUser(QString username, QString password, QString confirmPassword);
    void uploadFile(QString path);
    QString addStudent(QString reg, QString edu, QString first_name, QString middle_name, QString last_name, QString gender, QString grade, QString hl1, QString hl2, QString hl3, QString sl1, QString sl2, QString sl3);
    QString editStudent(QString reg, QString edu, QString first_name, QString middle_name, QString last_name, QString gender, QString hl1, QString hl2, QString hl3, QString sl1, QString sl2, QString sl3);
    QString addTeacher(QString name, QList<int> subjects);
    QString editTeacher(QString id, QString name, QList<int> subjects);
    QString addSubject(QString name);
    QString addSubject(QString name, QStringList teachers);
    QString editSubject(QString id, QString name);
    QStringList getStudent(int id);
    QStringList getBatch(QString id);
    QStringList getSubject(int id);
    QStringList getTeacher(int id);
    QStringList getGrade(int id);
    bool verifyStudentData(int grade);
    void refreshNewYear(QString path);
    void createTimetable(QString path, int grade);
    QString initials(QString string);
    QStringList getStudentLocation(int reg);

    void get_all_values(int grade);
    QList<QList<int>> permutations(QList<int> list);
    QList<QList<int>> generate_candidates(QList<int> subjects);
    bool verify_candidate(int candidate, QString block);
    QList<Batch> get_batches_from_block(int subject, int block);
    std::tuple <Student, QList<int>> calculate_optimum_candidate();
    Batch create_batch(int subject, int block);
    void insert_student(int student, QList<int> candidate);
    void assignBatches(int grade);
    void implementBatch();
    void implementTOKBatches();

    int get_student(int id);
    int get_remaining_student(int id);
    int get_subject(int id);
    int get_batch(QString id);
    int get_batch_by_block(QString id, int block);
    int get_teacher(int id);
    QString create_batch_id();
    QString qListIntToQString(QList<int> list);
    int binary_search(int key, QList<int> list);

private:
    void initDatabase();

    QSqlDatabase db;
    QSqlQuery query;

    QList<Student> remaining_students;
    QList<Student> all_students;
    QList<Teacher> all_teachers;
    QList<Subject> all_subjects;
    QList<Batch> all_batches;
    QMap<QString, QList<Batch>> all_batches_by_block;
};

#endif // DATABASE_H
