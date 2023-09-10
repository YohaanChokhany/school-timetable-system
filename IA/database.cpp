#include "database.h"
#include <algorithm>
#include <random>

using namespace QtConcurrent;
using namespace std;

Database::Database(QObject *parent)
    : QObject{parent}
{
    initDatabase();
}

void Database::uploadFile(QString path)
{
    path.remove("file://");
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return;
    }

    QList<QStringList> sheet;
    while (!file.atEnd()) {
        QList<QByteArray> line = file.readLine().split(',');
        QStringList row;
        for (const QString &cell : line) {
            row.append(cell.trimmed());
        }
        sheet.append(row);
    }

    int current = 2;

    while (sheet[current][0].toInt()) {
        QStringList row = sheet[current];
        QSqlQuery query;

        query.exec("INSERT into students (reg, edu, first_name, middle_name, last_name, gender, grade, hl_subject_1, hl_subject_2, hl_subject_3, sl_subject_1, sl_subject_2, sl_subject_3) "
                   "VALUES (" + row[2].trimmed() + ", '" + row[1].trimmed() + "', '" + row[3].trimmed() + "', '" + row[4].trimmed() + "', '" + row[5].trimmed() + "', '" + row[6].trimmed() + "', 11, '" + QVariant(global().code_to_id[row[7].toLower().trimmed()]).toString() + "', '" + QVariant(global().code_to_id[row[10].toLower().trimmed()]).toString() + "', '" + QVariant(global().code_to_id[row[13].toLower().trimmed()]).toString() + "', '" + QVariant(global().code_to_id[row[16].toLower().trimmed()]).toString() + "', '" + QVariant(global().code_to_id[row[19].toLower().trimmed()]).toString() + "', '" + QVariant(global().code_to_id[row[22].toLower().trimmed()]).toString() + "')");

        current += 1;
    }
}

QStringList Database::getSubjects()
{
    QStringList subjectsList;
    QSqlQuery query("SELECT * FROM subjects");
    while (query.next()) {
        subjectsList.append(query.value(2).toString());
    }

    return subjectsList;
}

QStringList Database::getStudents(QString search_query)
{
    QStringList studentsList;
    QSqlQuery query("SELECT * FROM students");
    while (query.next()) {
        if ((query.value(2).toString() + " " + query.value(3).toString() + " " + query.value(4).toString()).contains(search_query.trimmed(), Qt::CaseInsensitive) || (query.value(2).toString() + " " + query.value(4).toString()).contains(search_query.trimmed(), Qt::CaseInsensitive))
            studentsList.append(query.value(0).toString());
    }

    return studentsList;
}

QStringList Database::getStudent(int id)
{
    QSqlQuery query("SELECT * FROM students WHERE reg = " + QVariant(id).toString());

    Student student;
    query.next();

    QString name = query.value(2).toString() + " " + query.value(4).toString();
    if (query.value(3).toString() != "")
        name = query.value(2).toString() + " " + query.value(3).toString() + " " + query.value(4).toString();

    return { query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), name, query.value(6).toString(), query.value(7).toString(), query.value(8).toString(), query.value(9).toString(), query.value(10).toString(), query.value(11).toString(), query.value(12).toString(), query.value(13).toString(), query.value(14).toString(), query.value(15).toString(), query.value(16).toString(), query.value(17).toString(), query.value(18).toString(), query.value(19).toString(), query.value(20).toString() };
}

QStringList Database::getBatch(QString id)
{
    QSqlQuery query("SELECT * FROM batches WHERE id = '" + id + "'");
    query.next();

    return { query.value(0).toString(), global().code_to_subject[query.value(1).toInt()], query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString() };
}

QStringList Database::getSubject(int id)
{
    QSqlQuery query("SELECT * FROM subjects WHERE id = " + QVariant(id).toString());
    query.next();

    return { query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString() };
}

QStringList Database::getTeacher(int id)
{
    QSqlQuery query("SELECT * FROM teachers WHERE id = " + QVariant(id).toString());
    query.next();

    return { query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString(), query.value(8).toString(), query.value(9).toString() };
}

QStringList Database::getGrade(int id)
{
    QSqlQuery query("SELECT * FROM grades WHERE id = " + QVariant(id).toString());
    query.next();

    return { query.value(0).toString(), query.value(1).toString() };
}

QStringList Database::getStudentLocation(int reg)
{
    QStringList data;
    QList<QList<int>> timetable({
        {5, 6, 4, 2, 1},
        {7, 8, 6, 4, 3},
        {2, 5, 3, 6, 1},
        {4, 0, 2, 5, 3},
        {8, 7, 1, 2, 0}
    });
    QList<QString> class_times({"08:30 - 09:30", "09:30 - 10:30", "11:00 - 12:00", "12:00 - 1:00", "1:30 - 3:00"});

    QStringList student = getStudent(reg);

    data.append(QString::number(reg));
    data.append(student[7]);
    data.append(student[6]);

    QDateTime date = QDateTime::currentDateTime();
    QTime time = date.time();

    int period;
    int day = date.date().dayOfWeek();

    if (time < QTime(8, 30, 0))
        period = 6;
    else if (time < QTime(9, 30, 0))
        period = 1;
    else if (time < QTime(10, 30, 0))
        period = 2;
    else if (time < QTime(11, 0, 0))
        period = 7;
    else if (time < QTime(12, 0, 0))
        period = 3;
    else if (time < QTime(13, 0, 0))
        period = 4;
    else if (time < QTime(13, 30, 0))
        period = 8;
    else if (time < QTime(15, 0, 0))
        period = 5;
    else
        period = 9;

    period = 3;

    if (period < 6 && day < 6) {
        QString batch_id = student[13 + timetable[day - 1][period - 1]];
        data.append(class_times[period - 1]);
        if (batch_id != "") {
            QStringList batch = getBatch(batch_id);
            data.append(batch[1]);
            data.append(global().code_to_teacher[batch[4].toInt()]);
            data.append(global().code_to_location[batch[7].toInt()]);
        } else
            data.append("FREE");
    } else if (day > 5) {
        data.append("SCHOOL CLOSED");
    } else if (period == 6) {
        data.append("SCHOOL NOT STARTED");
    } else if (period == 7) {
        data.append("10:30 - 11:00");
        data.append("BREAK");
    } else if (period == 8) {
        data.append("1:00 - 1:30");
        data.append("LUNCH");
    } else if (period == 9) {
        data.append("SCHOOL HAS ENDED");
    }

    return data;
}

QString Database::addStudent(QString reg, QString edu, QString first_name, QString middle_name, QString last_name, QString gender, QString grade, QString hl1, QString hl2, QString hl3, QString sl1, QString sl2, QString sl3)
{
    QStringList edus = {"IGCSE", "ICSE", "New"};
    QString cgender = gender == "Male" ? "M" : "F";
    if (!reg.isEmpty() && !edu.isEmpty() && !first_name.isEmpty() && !last_name.isEmpty() && !gender.isEmpty() && !hl1.isEmpty() && !hl2.isEmpty() && !hl3.isEmpty() && !sl1.isEmpty() && !sl2.isEmpty() && !sl3.isEmpty()) {
        if (QVariant(reg).toInt()) {
            hl1.replace("and", "&");
            hl2.replace("and", "&");
            hl3.replace("and", "&");
            sl1.replace("and", "&");
            sl2.replace("and", "&");
            sl3.replace("and", "&");

            query.exec("INSERT into students (reg, edu, first_name, middle_name, last_name, gender, grade, hl_subject_1, hl_subject_2, hl_subject_3, sl_subject_1, sl_subject_2, sl_subject_3) "
                       "VALUES (" + reg.trimmed() + ", '" + edu.trimmed() + "', '" + first_name.trimmed() + "', '" + middle_name.trimmed() + "', '" + last_name.trimmed() + "', '" + cgender.trimmed() + "', " + grade.trimmed() + ", '" + QVariant(global().subject_to_code[hl1]).toString() + "', '" + QVariant(global().subject_to_code[hl2]).toString() + "', '" + QVariant(global().subject_to_code[hl3]).toString() + "', '" + QVariant(global().subject_to_code[sl1]).toString() + "', '" + QVariant(global().subject_to_code[sl2]).toString() + "', '" + QVariant(global().subject_to_code[sl3]).toString() + "')");
            return "SUCCESS";
        } else {
            return "INCORRECT REGISTRATION NO.";
        }
    } else {
        return "INCOMPLETE";
    }
}

QString Database::editStudent(QString reg, QString edu, QString first_name, QString middle_name, QString last_name, QString gender, QString hl1, QString hl2, QString hl3, QString sl1, QString sl2, QString sl3)
{
    QStringList edus = {"IGCSE", "ICSE", "New"};
    QString cgender = gender == "Male" ? "M" : "F";
    if (!reg.isEmpty() && !edu.isEmpty() && !first_name.isEmpty() && !last_name.isEmpty() && !gender.isEmpty() && !hl1.isEmpty() && !hl2.isEmpty() && !hl3.isEmpty() && !sl1.isEmpty() && !sl2.isEmpty() && !sl3.isEmpty()) {
        hl1.replace("and", "&");
        hl2.replace("and", "&");
        hl3.replace("and", "&");
        sl1.replace("and", "&");
        sl2.replace("and", "&");
        sl3.replace("and", "&");

        QSqlQuery query("UPDATE students SET first_name = '" + first_name.trimmed() + "', middle_name = '" + middle_name.trimmed() + "', last_name = '" + last_name.trimmed() + "', edu = '" + edu.trimmed() + "', gender = '" + cgender.trimmed() + "', "
                   "hl_subject_1 = '" + QVariant(global().subject_to_code[hl1]).toString() + "', hl_subject_2 = '" + QVariant(global().subject_to_code[hl2]).toString() + "', hl_subject_3 = '" + QVariant(global().subject_to_code[hl3]).toString() + "', "
                   "sl_subject_1 = '" + QVariant(global().subject_to_code[sl1]).toString() + "', sl_subject_2 = '" + QVariant(global().subject_to_code[sl2]).toString() + "', sl_subject_3 = '" + QVariant(global().subject_to_code[sl3]).toString() + "' "
                   "WHERE reg = " + reg.trimmed());
        return "SUCCESS";
    } else {
        return "INCOMPLETE";
    }
}

QString Database::addTeacher(QString name, QList<int> subjects)
{
    if (!name.isEmpty() && !subjects.isEmpty()) {
        QStringList all_subjects = getSubjects();
        QString subject_str = "";

        for (int subject : subjects) {
            subject_str.append(QVariant(global().subject_to_code[all_subjects[subject]]).toString() + ", ");
        }

        query.exec("INSERT into teachers (name, subjects) "
                   "VALUES ('" + name.trimmed() + "', '" + subject_str.mid(0, subject_str.length() - 2).trimmed() + "')");

        query.exec("SELECT (name, subjects, block_1, block_2, block_3, block_4, block_5, block_6, block_7) FROM teachers ORDER BY name DESC");
        return "SUCCESS";
    } else {
        return "INCOMPLETE";
    }
}

QString Database::editTeacher(QString id, QString name, QList<int> subjects)
{
    if (!id.isEmpty() && !name.isEmpty() && !subjects.isEmpty()) {
        QString subject_str = "";
        for (int subject : subjects) {
            subject_str.append(QVariant(subject).toString() + ", ");
        }
        QSqlQuery query("UPDATE teachers SET name = '" + name.trimmed() + "', subjects = '" + subject_str.mid(0, subject_str.length() - 2).trimmed() + "' WHERE id = " + id.trimmed());
        return "SUCCESS";
    } else {
        return "INCOMPLETE";
    }
}

QString Database::addSubject(QString name)
{
    if (!name.isEmpty()) {
        QSqlQuery query("SELECT * FROM subjects WHERE name = '" + name.trimmed() + "'");
        if (query.next())
            return "INVALID SUBJECT";

        query.exec("INSERT INTO subjects (name) VALUES ('" + name.trimmed() + "')");
        return "SUCCESS";
    } else {
        return "INCOMPLETE";
    }
}

QString Database::addSubject(QString name, QStringList teachers)
{
    if (!name.isEmpty()) {
        QSqlQuery query("SELECT * FROM subjects WHERE name = '" + name.trimmed() + "'");
        if (query.next())
            return "INVALID SUBJECT";

        query.exec("INSERT INTO subjects (name, teachers) VALUES ('" + name.trimmed() + "', '" + teachers.join(", ").trimmed() + "')");
        return "SUCCESS";
    } else {
        return "INCOMPLETE";
    }
}

QString Database::editSubject(QString id, QString name)
{
    if (!name.isEmpty()) {
        QSqlQuery query("SELECT * FROM subjects WHERE name = '" + name.trimmed() + "'");
        if (query.next()) {
            return "INVALID SUBJECT";
        }

        QSqlQuery query1("UPDATE subjects SET name = '" + name.trimmed() + "' WHERE id = " + id.trimmed());
        return "SUCCESS";
    } else {
        return "INCOMPLETE";
    }
}

bool Database::verifyStudentData(int grade)
{
    QSqlQuery query("SELECT * FROM students WHERE grade = " + QVariant(grade).toString());
    if (!query.next()) {
        return false;
    }
    query.previous();

    while (query.next()) {
        if (query.value(7).toString().isEmpty() || query.value(8).toString().isEmpty() || query.value(9).toString().isEmpty() || query.value(10).toString().isEmpty() || query.value(11).toString().isEmpty() || query.value(12).toString().isEmpty()) {
            return false;
        }
    }

    return true;
}

void Database::refreshNewYear(QString path)
{
    path.remove("file://");
    QSqlQuery tokQ("SELECT * FROM grades WHERE id = 12");
    tokQ.next();
    int tok_batch = tokQ.value(2).toInt();

    if (tokQ.value(1).toInt() == 1) {
        QDir dir(path);
        dir.mkdir(path);

        QFile file(path + "/Main.csv");
        if (file.open(QIODevice::WriteOnly | QFile::Text)) {
            QTextStream csv(&file);
            csv << "Year 12 - Batch Data\n\n";
            csv << "Sr No.," << "Program," << "Registration No.," << "First Name," << "Middle Name," << "Last Name," << "Gender," << "HL1," << "Teacher," << "HL2," << "Teacher," << "HL3," << "Teacher," << "SL1," << "Teacher," << "SL2," << "Teacher," << "SL3," << "Teacher" << "TOK" << "Teacher\n";

            QSqlQuery query ("SELECT * FROM students WHERE grade = 12");
            int counter = 1;
            while (query.next()) {
                csv << counter << "," << query.value(1).toString() << "," << query.value(0).toString() << "," << query.value(2).toString() << "," << query.value(3).toString() << "," << query.value(4).toString() << "," << query.value(5).toString() << "," << (query.value(7).toInt() != 0 ? global().id_to_code[query.value(7).toInt()] + "," + initials(global().code_to_teacher[getBatch(query.value(13).toString())[4].toInt()]).mid(1) + "," : ",,") << (query.value(8).toInt() != 0 ? global().id_to_code[query.value(8).toInt()] + "," + initials(global().code_to_teacher[getBatch(query.value(14).toString())[4].toInt()]).mid(1) + "," : ",,") << (query.value(9).toInt() != 0 ? global().id_to_code[query.value(9).toInt()] + "," + initials(global().code_to_teacher[getBatch(query.value(15).toString())[4].toInt()]).mid(1) + "," : ",,") << (query.value(10).toInt() != 0 ? global().id_to_code[query.value(10).toInt()] + "," + initials(global().code_to_teacher[getBatch(query.value(16).toString())[4].toInt()]).mid(1) + "," : ",,") << (query.value(11).toInt() != 0 ? global().id_to_code[query.value(11).toInt()] + "," + initials(global().code_to_teacher[getBatch(query.value(17).toString())[4].toInt()]).mid(1) + "," : ",,") << (query.value(12).toInt() != 0 ? global().id_to_code[query.value(12).toInt()] + "," + initials(global().code_to_teacher[getBatch(query.value(18).toString())[4].toInt()]).mid(1): ",") << "\n";

                counter ++;
            }
            file.close();
        }

        for (int i = 1; i < 9; i++) {
            if (i == 7 and tok_batch != i)
                continue;
            else if (i == 8 and tok_batch != i)
                continue;

            QString block_str = QString::number(i);
            QFile block(path + "/Block" + block_str + ".csv");
            if (block.open(QIODevice::WriteOnly | QFile::Text)) {
                QTextStream csv(&block);
                csv << "Year 12 - Block " + block_str + "\n";

                QSqlQuery query ("SELECT * FROM batches WHERE grade = 12 AND block = " + block_str);
                while (query.next()) {
                    csv << ",\n" << '"' + global().code_to_subject[query.value(1).toInt()] + '"' + " " << query.value(2).toString() << " - " << global().code_to_teacher[query.value(4).toInt()] << " (" << initials(global().code_to_teacher[query.value(4).toInt()]).mid(1) << ") - Block " << block_str << "\n,\n";
                    csv << "Sr No.," << "Program," << "Registration No.," << "First Name," << "Middle Name," << "Last Name," << "Gender\n";

                    int counter = 1;
                    QStringList students = query.value(6).toString().split(", ");
                    for (QString student : students) {
                        QStringList data = getStudent(QVariant(student).toInt());
                        csv << counter << "," << data[1] << "," << data[0] << "," << data[2] << "," << data[3] << "," << data[4] << "," << data[5] << "\n";

                        counter ++;
                    }
                }
                block.close();
            }
        }

        QSqlQuery("DELETE FROM students WHERE grade = 12");
        QSqlQuery query("SELECT * FROM batches WHERE grade = 12");
        while (query.next())
            QSqlQuery("UPDATE teachers SET block_" + query.value(3).toString() + " = '' WHERE id = " + query.value(4).toString());
        QSqlQuery("DELETE FROM batches WHERE grade = 12");
    }
    QSqlQuery query("SELECT * FROM students WHERE grade = 11");
    while (query.next()) {
        QSqlQuery("UPDATE students SET grade = 12 WHERE reg = " + query.value(0).toString());
    }

    query.exec("SELECT * FROM batches WHERE grade = 11");
    while (query.next()) {
        QSqlQuery("UPDATE batches SET grade = 12 WHERE id = '" + query.value(0).toString() + "'");
    }

    query.exec("SELECT * FROM grades WHERE id = 11");
    if (query.next()) {
        QString tok11 = query.value(2).toInt() == 7 ? "8" : "7";
        QString tok12 = query.value(2).toInt() == 7 ? "7" : "8";
        QSqlQuery("UPDATE grades SET assigned = 0, tok = " + tok11 + " WHERE id = 11");
        QSqlQuery("UPDATE grades SET assigned = 1, tok = " + tok12 + " WHERE id = 12");
    }
}

QString Database::loginUser(QString username, QString password)
{
    QString hashed_password = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex();

    QSqlQuery query;
    query.exec("SELECT * FROM users WHERE username = '" + username + "'");

    while (query.next()) {
        QString hashee = query.value(2).toString();
        if (hashee == hashed_password) {
            return "SUCCESS";
        } else {
            return "Incorrect Password";
        }
    }
    return "Incorrect Username";
}

QString Database::addUser(QString username, QString password, QString confirmPassword)
{
    QRegularExpression regex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                          QRegularExpression::CaseInsensitiveOption);

    if (!username.isEmpty()) {
        if (regex.match(username).hasMatch()) {
            if (password.size() >= 8) {
                if (password == confirmPassword) {
                    QSqlQuery query1("SELECT * FROM users WHERE username = '" + username + "'");
                    if (query1.next())
                        return "USERNAME EXISTS";

                    QString hashed_password = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex();
                    QSqlQuery query2("INSERT INTO users (username, password) VALUES ('" + username + "', '" + hashed_password + "')");

                    return "SUCCESS";
                } else {
                    return "DID NOT MATCH";
                }
            } else {
                return "INVALID PASSWORD";
            }
        } else {
            return "INVALID EMAIL";
        }
    } else {
        return "INCOMPLETE";
    }
}

void Database::get_all_values(int grade)
{
    QSqlDatabase db = QSqlDatabase::database("SECONDARY");
    all_students = QList<Student>();
    all_teachers = QList<Teacher>();
    all_subjects = QList<Subject>();
    all_batches = QList<Batch>();
    all_batches_by_block = QMap<QString, QList<Batch>>();

    QSqlQuery query("SELECT * FROM students WHERE grade = " + QVariant(grade).toString(), db);
    while (query.next()) {
        Student student;
        student.reg = query.value(0).toInt();
        student.edu = query.value(1).toString();
        student.first_name = query.value(2).toString();
        student.middle_name = query.value(3).toString();
        student.last_name = query.value(4).toString();
        student.name = query.value(2).toString() + " " + query.value(4).toString();
        if (query.value(3).toString() != "")
            student.name = query.value(2).toString() + " " + query.value(3).toString() + " " + query.value(4).toString();
        student.gender = query.value(5).toString();
        student.hl1 = query.value(7).toString();
        student.hl2 = query.value(8).toString();
        student.hl3 = query.value(9).toString();
        student.sl1 = query.value(10).toString();
        student.sl2 = query.value(11).toString();
        student.sl3 = query.value(12).toString();
        student.classes["block_1"] = query.value(13).toString();
        student.classes["block_2"] = query.value(14).toString();
        student.classes["block_3"] = query.value(15).toString();
        student.classes["block_4"] = query.value(16).toString();
        student.classes["block_5"] = query.value(17).toString();
        student.classes["block_6"] = query.value(18).toString();
        student.classes["block_7"] = query.value(19).toString();
        student.subjects = { student.hl1.toInt(), student.hl2.toInt(), student.hl3.toInt(), student.sl1.toInt(), student.sl2.toInt(), student.sl3.toInt() };
        all_students.append(student);
    }
    remaining_students = all_students;

    query.exec("SELECT * FROM teachers");
    while (query.next()) {
        Teacher teacher;
        teacher.id = query.value(0).toInt();
        teacher.name = query.value(1).toString();
        teacher.subjects = query.value(2).toString().split(", ");
        teacher.block_1 = query.value(3).toString();
        teacher.block_2 = query.value(4).toString();
        teacher.block_3 = query.value(5).toString();
        teacher.block_4 = query.value(6).toString();
        teacher.block_5 = query.value(7).toString();
        teacher.block_6 = query.value(8).toString();
        teacher.block_7 = query.value(9).toString();
        teacher.blocks["block_1"] = teacher.block_1;
        teacher.blocks["block_2"] = teacher.block_2;
        teacher.blocks["block_3"] = teacher.block_3;
        teacher.blocks["block_4"] = teacher.block_4;
        teacher.blocks["block_5"] = teacher.block_5;
        teacher.blocks["block_6"] = teacher.block_6;
        teacher.blocks["block_7"] = teacher.block_7;
        all_teachers.append(teacher);
    }

    query.exec("SELECT * FROM subjects");
    while (query.next()) {
        Subject subject;
        subject.id = query.value(0).toInt();
        subject.code = query.value(1).toString();
        subject.name = query.value(2).toString();
        subject.teachers = query.value(3).toString().split(", ");
        subject.batches = query.value(4).toString().split(", ");
        all_subjects.append(subject);
    }

    for (int block = 1; block <= 6; block++) {
        all_batches_by_block["block_" + QVariant(block).toString()] = QList<Batch>{};
    }
}

QList<QList<int>> Database::permutations(QList<int> list)
{
    QList<QList<int>> permutations;
    for (int x = 0; x < list.length(); x++) {
        for (int y = 0; y < list.length(); y++) {
            if (x != y) {
                for (int z = 0; z < list.length(); z++) {
                    if (z != y && z != x) {
                        permutations.append(QList{list[x], list[y], list[z]});
                    }
                }
            }
        }
    }

    return permutations;
}

QList<QList<int>> Database::generate_candidates(QList<int> subjects)
{
    QList<QList<int>> list1 = permutations(subjects.mid(0, 3));
    QList<QList<int>> list2 = permutations(subjects.mid(3, 3));

    QList<QList<int>> unique_combinations;
    for (QList<int> elem1 : list1) {
        for (QList<int> elem2 : list2) {
            QList<int> combination = elem1;
            combination.append(elem2);

            unique_combinations.append(combination);
        }
    }

    return unique_combinations;
}

bool Database::verify_candidate(int candidate, QString block)
{
    QList<Batch> batches = all_batches_by_block[block];

    for (int i = 0; i < batches.length(); i++) {
        if (batches[i].subject == candidate && batches[i].students.length() < 17) {
            return true;
        }
    }

    for (int i = 0; i < all_subjects[get_subject(candidate)].teachers.length(); i++) {
        if (all_teachers[get_teacher(all_subjects[get_subject(candidate)].teachers[i].toInt())].blocks[block] == "")
            return true;
    }
    return false;
}

QList<Batch> Database::get_batches_from_block(int subject, int block)
{
    QList<Batch> batches;
    for (Batch batch : all_batches_by_block["block_" + QVariant(block).toString()]) {
        if (batch.subject == subject and batch.students.length() < 17)
            batches.append(batch);
    }

    return batches;
}

std::tuple <Student, QList<int>> Database::calculate_optimum_candidate()
{
    std::tuple<Student, QList<int>> optimum_student;
    int optimum_score = -1;

    std::random_device rd;
    std::mt19937 rng(rd());

    std::shuffle(remaining_students.begin(), remaining_students.end(), rng);

    for (Student student : remaining_students) {
        QList<QList<int>> order_candidates = generate_candidates(student.subjects);
        std::shuffle(order_candidates.begin(), order_candidates.end(), rng);
        QList<int> optimum_candidate;
        int student_optimum_score = -1;

        for (QList<int> candidate : order_candidates) {
            int candidate_score = 6;

            for (int i = 0; i < candidate.length(); i ++) {
                if (candidate[i] != 0) {
                    if (verify_candidate(candidate[i], "block_" + QVariant(i + 1).toString())) {
                        if (get_batches_from_block(candidate[i], i + 1).length() == 0)
                            candidate_score -= 1;
                    } else {
                        candidate_score = -1;
                        break;
                    }
                } else {
                    candidate_score -= 1;
                }
            }

            if (candidate_score == 6) {
                return make_tuple(student, candidate);
            } else if (candidate_score > student_optimum_score) {
                optimum_candidate = candidate;
                student_optimum_score = candidate_score;
            }
        }

        if (student_optimum_score > optimum_score) {
            optimum_student = make_tuple(student, optimum_candidate);
            optimum_score = student_optimum_score;
        }
    }
    return optimum_student;
}

Batch Database::create_batch(int subject, int block)
{
    Batch batch = Batch();

    batch.level = "SL";
    if (block < 4)
        batch.level = "HL";

    batch.subject = subject;
    batch.block = block;
    batch.id = create_batch_id();

    int teacher;
    int free_subjects = 0;
    for (int i = 0; i < all_teachers.length(); i++) {
        if (all_teachers[i].subjects.contains(QVariant(subject).toString()) && all_teachers[i].blocks["block_" + QVariant(block).toString()] == "") {
            int free = 0;
            for (int block = 0; block < all_teachers[i].blocks.values().length(); block++) {
                if (all_teachers[i].blocks.values()[block] == "")
                    free ++;
            }

            if (free > free_subjects) {
                free_subjects = free;
                teacher = i;
            }
        }
    }

    batch.teacher = all_teachers[teacher].id;
    all_teachers[teacher].blocks["block_" + QVariant(block).toString()] = batch.id;

    all_batches_by_block["block_" + QVariant(block).toString()].append(batch);
    all_batches.append(batch);
    return batch;
}

void Database::insert_student(int student, QList<int> candidate)
{
    for (int i = 0; i < candidate.length(); i++) {
        if (candidate[i] != 0) {
            QList<Batch> batches = get_batches_from_block(candidate[i], i + 1);
            if (batches.length() > 0) {
                QString chosen_batch = batches[int(QRandomGenerator::global()->generateDouble() * batches.length())].id;
                all_batches[get_batch(chosen_batch)].students.append(all_students[student].reg);
                all_batches_by_block["block_" + QVariant(i + 1).toString()][get_batch_by_block(chosen_batch, i + 1)].students.append(all_students[student].reg);

                all_students[student].classes["block_" + QVariant(i + 1).toString()] = QVariant(all_batches[get_batch(chosen_batch)].id).toString();
            } else {
                Batch created_batch = create_batch(candidate[i], i + 1);
                all_batches[get_batch(created_batch.id)].students.append(all_students[student].reg);
                all_batches_by_block["block_" + QVariant(i + 1).toString()][get_batch_by_block(created_batch.id, i + 1)].students.append(all_students[student].reg);

                all_students[student].classes["block_" + QVariant(i + 1).toString()] = QVariant(created_batch.id).toString();
            }
        }
    }

    remaining_students.removeAt(get_remaining_student(all_students[student].reg));
}

void Database::assignBatches(int grade)
{
    int epochs = 10;
    QFuture<void> future = run([=] {
        emit progress(1, epochs + 1);
        optimum_batches = QList<Batch>(200);

        QSqlDatabase sqlite_db = QSqlDatabase::addDatabase("QSQLITE", "SECONDARY");
        sqlite_db.setDatabaseName("../Databases/db.sqlite");
        sqlite_db.open();

        for (int i = 0; i < epochs; i++) {
            bool error = false;

            get_all_values(grade);
            remaining_students = all_students;

            for (int x = 0; x < all_students.length(); x ++) {
                std::tuple <Student, QList<int>> candidate_info = calculate_optimum_candidate();

                if (get<1>(candidate_info).size() == 0) {
                    error = true;
                    break;
                }

                insert_student(get_student(get<0>(candidate_info).reg), get<1>(candidate_info));
            }

            if (error)
                continue;

            if (all_batches.length() < optimum_batches.length())
                optimum_batches = all_batches;

            qDebug() << (i + 1) << "/" << epochs << optimum_batches.length();
            emit progress(i + 2, epochs + 1);
        }

        get_all_values(grade);

        implementBatch();
        implementTOKBatches();
        QSqlQuery("UPDATE grades SET assigned = 1 WHERE id = 11", sqlite_db);
    });
}

void Database::implementBatch()
{
    QSqlDatabase db = QSqlDatabase::database("SECONDARY");
    for (int i = 0; i < all_students.length(); i++)
        all_students[i].subjects = {0, 0, 0, 0, 0, 0};

    QList<QList<int>> free_locations;
    for (int i = 0; i < 6; i++) {
        QList<int> block;
        QSqlQuery query("SELECT * FROM locations WHERE block_" + QString::number(i + 2) + " = ''", db);
        while (query.next())
            block.append(query.value(0).toInt());
        free_locations.append(block);
    }

    for (Batch batch : optimum_batches) {

        all_subjects[get_subject(batch.subject)].batches.append(batch.id);
        all_teachers[get_teacher(batch.teacher)].blocks["block_" + QVariant(batch.block).toString()] = batch.id;

        for (int student : batch.students) {
            all_students[get_student(student)].classes["block_" + QVariant(batch.block).toString()] = batch.id;
            all_students[get_student(student)].subjects[batch.block - 1] = batch.subject;
        }

        int pos = arc4random() % free_locations[batch.block - 1].size();
        QString location = QVariant(free_locations[batch.block - 1][pos]).toString();
        free_locations[batch.block - 1].remove(pos);

        QSqlQuery("INSERT INTO batches (id, subject, level, block, teacher, grade, students, location) VALUES ('" + batch.id + "', " + QVariant(batch.subject).toString() + ", '" + batch.level + "', " + QVariant(batch.block).toString() + ", " + QVariant(batch.teacher).toString() + ", 11, '" + qListIntToQString(batch.students) + "', " + location + ")", db);
    }
    for (Student student : all_students)
        QSqlQuery("UPDATE students SET hl_subject_1 = " + QVariant(student.subjects[0]).toString() + ", hl_subject_2 = " + QVariant(student.subjects[1]).toString() + ", hl_subject_3 = " + QVariant(student.subjects[2]).toString() + ", sl_subject_1 = " + QVariant(student.subjects[3]).toString() + ", sl_subject_2 = " + QVariant(student.subjects[4]).toString() + ", sl_subject_3 = " + QVariant(student.subjects[5]).toString() + ", block_1 = '" + student.classes["block_1"] + "', block_2 = '" + student.classes["block_2"] + "', block_3 = '" + student.classes["block_3"] + "', block_4 = '" + student.classes["block_4"] + "', block_5 = '" + student.classes["block_5"] + "', block_6 = '" + student.classes["block_6"] + "' WHERE reg = " + QVariant(student.reg).toString(), db);
    for (Subject subject : all_subjects)
        QSqlQuery("UPDATE subjects SET batches = '" + subject.batches.join(", ").mid(2) + "' WHERE id = " + QVariant(subject.id).toString(), db);
    for (Teacher teacher : all_teachers)
        QSqlQuery("UPDATE teachers SET block_1 = '" + teacher.blocks["block_1"] + "', block_2 = '" + teacher.blocks["block_2"] + "', block_3 = '" + teacher.blocks["block_3"] + "', block_4 = '" + teacher.blocks["block_4"] + "', block_5 = '" + teacher.blocks["block_5"] + "', block_6 = '" + teacher.blocks["block_6"] + "' WHERE id = " + QVariant(teacher.id).toString(), db);
}

void Database::implementTOKBatches()
{
    QSqlDatabase db = QSqlDatabase::database("SECONDARY");

    QSqlQuery query("SELECT * FROM grades WHERE id = 11", db);
    query.next();
    int block = query.value(2).toInt();

    QString batches = "";
    QList<Batch> tokBatches;
    for (Teacher teacher : all_teachers) {
        if (teacher.subjects.contains("22")) {
            Batch batch;
            batch.id = create_batch_id();
            batch.subject = 22;
            batch.level = "";
            batch.block = block;
            batch.teacher = teacher.id;

            tokBatches.append(batch);

            batches.append(batch.id + ", ");

            QSqlQuery("UPDATE teachers SET block_" + QVariant(block).toString() + " = '" + batch.id + "' WHERE id = " + QVariant(teacher.id).toString(), db);
        }
    }

    int num = tokBatches.length();
    for (int i = 0; i < all_students.length(); i++) {
        tokBatches[i % num].students.append(all_students[i].reg);
        QSqlQuery("UPDATE students SET block_" + QVariant(block).toString() + " = '" + tokBatches[i % num].id + "' WHERE reg = " + QVariant(all_students[i].reg).toString(), db);
    }

    QList<int> free_locations;
    QSqlQuery free_locations_query("SELECT * FROM locations WHERE block_" + QVariant(block).toString() + " = ''", db);
    while (free_locations_query.next()) {
        free_locations.append(free_locations_query.value(0).toInt());
    }

    for (Batch batch : tokBatches) {
        int pos = arc4random() % free_locations.size();
        QString location = QVariant(free_locations[pos]).toString();
        free_locations.remove(pos);

        QSqlQuery("INSERT INTO batches (id, subject, level, block, teacher, grade, students, location) VALUES ('" + batch.id + "', " + QVariant(batch.subject).toString() + ", '" + batch.level + "', " + QVariant(batch.block).toString() + ", " + QVariant(batch.teacher).toString() + ", 11, '" + qListIntToQString(batch.students) + "', " + location + ")", db);
    }
    QSqlQuery("UPDATE subjects SET batches = '" + batches.mid(0, batches.length() - 2) + "' WHERE id = '22'", db);
}

void Database::createTimetable(QString path, int grade) {
    path.remove("file://");

    QMap<int, QString> id_to_code = global().id_to_code;
    QMap<int, QString> code_to_teacher = global().code_to_teacher;
    QMap<int, QString> code_to_location = global().code_to_location;
    QMap<int, QString> code_to_subject = global().code_to_subject;

    QFuture<void> future = run([=] {
        QSqlDatabase sqlite_db = QSqlDatabase::addDatabase("QSQLITE", "SECONDARY");
        sqlite_db.setDatabaseName("../Databases/db.sqlite");
        sqlite_db.open();

        QSqlDatabase db = QSqlDatabase::database("SECONDARY");

        int total = 1;
        int counter = 0;

        QSqlQuery students("SELECT * FROM students WHERE grade = " + QVariant(grade).toString(), db);
        while (students.next())
            total++;
        QSqlQuery teachers("SELECT * FROM teachers", db);
        while(teachers.next())
            total++;

        QDir dir(path);
        dir.mkdir(path);
        dir.mkdir(path + "/Students");
        dir.mkdir(path + "/Teachers");

        QString tok_block;
        QSqlQuery tokQ("SELECT * FROM grades WHERE id = " + QVariant(grade).toString(), db);
        if (tokQ.next())
            tok_block = tokQ.value(2).toString();

        QList<QString> cell_contents;
        for (int i = 0; i < 8; i++) {
            QSqlQuery blocks("SELECT * FROM batches WHERE grade = " + QVariant(grade).toString() + " AND block = " + QVariant(i + 1).toString(), db);
            QString cell;
            while (blocks.next())
                cell.append( id_to_code[blocks.value(1).toInt()].toUpper() + " " + blocks.value(2).toString() + " " + initials(code_to_teacher[blocks.value(4).toInt()]).mid(1) + " <strong>" + code_to_location[blocks.value(7).toInt()] + "</strong><br>");
            cell_contents.append(cell);
        }

        QString html =
        "<table border='1' style='border-collapse: collapse; border-color: black'>"
            "<tr>"
                "<td colspan='8'><h1 align=center>TIMETABLE</h1></td>"
            "</tr>"
            "<tr>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' width='40'></td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' width='71'><strong>1</strong></td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' width='71'><strong>2</strong></td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' width='71'><strong>3</strong></td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' width='71'><strong>4</strong></td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' width='36'><strong>5</strong></td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' width='36'><strong>6</strong></td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' width='70'><strong>7</strong></td>"
            "</tr>"
            "<tr>"
                "<td style='font-size: 5pt; text-align: center; vertical-align: middle'></td>"
                "<td style='font-size: 5pt; text-align: center; vertical-align: middle'><strong>08:30 - 09:30</strong></td>"
                "<td style='font-size: 5pt; text-align: center; vertical-align: middle'><strong>09:30 - 10:30</strong></td>"
                "<td style='font-size: 5pt; text-align: center; vertical-align: middle'><strong>11:00 - 12:00</strong></td>"
                "<td style='font-size: 5pt; text-align: center; vertical-align: middle'><strong>12:00 - 1:00</strong></td>"
                "<td style='font-size: 5pt; text-align: center; vertical-align: middle'><strong>1:30 - 2:15</strong></td>"
                "<td style='font-size: 5pt; text-align: center; vertical-align: middle'><strong>2:15 - 3:00</strong></td>"
                "<td style='font-size: 5pt; text-align: center; vertical-align: middle'><strong>3:00 - 4:00</strong></td>"
            "</tr>"
            "<tr>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle'> Monday</td>"
                "<td style='font-size: 6pt; background: #83EEFD'>"
                    "<strong>Block 5</strong><br><br>" + cell_contents[4].mid(0, cell_contents[4].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #E39FF6'>"
                    "<strong>Block 6</strong><br><br>" + cell_contents[5].mid(0, cell_contents[5].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #07C04A'>"
                    "<strong>Block 4</strong><br><br>" + cell_contents[3].mid(0, cell_contents[3].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #FA8128'>"
                    "<strong>Block 2</strong><br><br>" + cell_contents[1].mid(0, cell_contents[1].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #EF0F1F' colspan='2'>"
                    "<strong>Block 1</strong><br><br>" + cell_contents[0].mid(0, cell_contents[0].length() - 4) + "</td>"
                "<td style='font-size: 6pt'></td>"
            "</tr>"
            "<tr>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle'>Tuesday</td>"
                  + (tok_block == "7" ? "<td style='font-size: 6pt; background: #AF69EF'><strong>Block 7</strong><br><br>" + cell_contents[6].mid(0, cell_contents[6].length() - 4) : "<td style='font-size: 6pt; text-align: center; vertical-align: middle'><strong>OPEN</strong>") + "</td>"
                  + (tok_block == "8" ? "<td style='font-size: 6pt; background: #AF69EF'><strong>Block 8</strong><br><br>" + cell_contents[7].mid(0, cell_contents[7].length() - 4) : "<td style='font-size: 6pt; text-align: center; vertical-align: middle'><strong>OPEN</strong>") + "</td>"
                "<td style='font-size: 6pt; background: #E39FF6'>"
                    "<strong>Block 6</strong><br><br>" + cell_contents[5].mid(0, cell_contents[5].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #07C04A'>"
                    "<strong>Block 4</strong><br><br>" + cell_contents[3].mid(0, cell_contents[3].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #F9E076' colspan='2'>"
                    "<strong>Block 3</strong><br><br>" + cell_contents[2].mid(0, cell_contents[2].length() - 4) + "</td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle'><strong>CAS</strong></td>"
            "</tr>"
            "<tr>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle'>Wednesday</td>"
                "<td style='font-size: 6pt; background: #FA8128'>"
                    "<strong>Block 2</strong><br><br>" + cell_contents[1].mid(0, cell_contents[1].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #83EEFD'>"
                    "<strong>Block 5</strong><br><br>" + cell_contents[4].mid(0, cell_contents[4].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #F9E076'>"
                    "<strong>Block 3</strong><br><br>" + cell_contents[2].mid(0, cell_contents[2].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #E39FF6'>"
                    "<strong>Block 6</strong><br><br>" + cell_contents[5].mid(0, cell_contents[5].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #EF0F1F' colspan='2'>"
                    "<strong>Block 1</strong><br><br>" + cell_contents[0].mid(0, cell_contents[0].length() - 4) + "</td>"
                "<td style='font-size: 6pt'></td>"
            "</tr>"
            "<tr>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle'>Thursday</td>"
                "<td style='font-size: 6pt; background: #07C04A'>"
                    "<strong>Block 4</strong><br><br>" + cell_contents[3].mid(0, cell_contents[3].length() - 4) + "</td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle'><strong>OPEN</strong></td>"
                "<td style='font-size: 6pt; background: #FA8128'>"
                    "<strong>Block 2</strong><br><br>" + cell_contents[1].mid(0, cell_contents[1].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #83EEFD'>"
                    "<strong>Block 5</strong><br><br>" + cell_contents[4].mid(0, cell_contents[4].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #F9E076' colspan='2'>"
                    "<strong>Block 3</strong><br><br>" + cell_contents[2].mid(0, cell_contents[2].length() - 4) + "</td>"
                "<td style='font-size: 6pt'></td>"
            "</tr>"
            "<tr>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle'>Friday</td>"
                  + (tok_block == "8" ? "<td style='font-size: 6pt; background: #AF69EF'><strong>Block 8</strong><br><br>" + cell_contents[7].mid(0, cell_contents[7].length() - 4) : "<td style='font-size: 6pt; text-align: center; vertical-align: middle'><strong>OPEN</strong>") + "</td>"
                  + (tok_block == "7" ? "<td style='font-size: 6pt; background: #AF69EF'><strong>Block 7</strong><br><br>" + cell_contents[6].mid(0, cell_contents[6].length() - 4) : "<td style='font-size: 6pt; text-align: center; vertical-align: middle'><strong>OPEN</strong>") + "</td>"
                "<td style='font-size: 6pt; background: #EF0F1F'>"
                    "<strong>Block 1</strong><br><br>" + cell_contents[0].mid(0, cell_contents[0].length() - 4) + "</td>"
                "<td style='font-size: 6pt; background: #FA8128'>"
                    "<strong>Block 2</strong><br><br>" + cell_contents[1].mid(0, cell_contents[1].length() - 4) + "</td>"
                "<td style='font-size: 6pt; text-align: center; vertical-align: middle' colspan='3'><strong>CAS</strong></td>"
            "</tr>"
        "</table>";

        counter++;
        emit downloadProgress(counter, total);

        QTextDocument document;
        document.setHtml(html);

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(path + "/Timetable.pdf");
        printer.setPageMargins(QMarginsF(0, 0, 0, 0));

        document.print(&printer);

        students.exec("SELECT * FROM students WHERE grade = " + QVariant(grade).toString());
        while (students.next()) {
            QString block1, block1_location;
            QSqlQuery block1_query("SELECT * FROM batches WHERE id = '" + students.value(13).toString() + "'", db);
            while (block1_query.next()) {
                block1 = code_to_subject[block1_query.value(1).toInt()];
                block1_location = code_to_location[block1_query.value(7).toInt()];
            }

            QString block2, block2_location;
            QSqlQuery block2_query("SELECT * FROM batches WHERE id = '" + students.value(14).toString() + "'", db);
            while (block2_query.next()) {
                block2 = code_to_subject[block2_query.value(1).toInt()];
                block2_location = code_to_location[block2_query.value(7).toInt()];
            }

            QString block3, block3_location;
            QSqlQuery block3_query("SELECT * FROM batches WHERE id = '" + students.value(15).toString() + "'", db);
            while (block3_query.next()) {
                block3 = code_to_subject[block3_query.value(1).toInt()];
                block3_location = code_to_location[block3_query.value(7).toInt()];
            }

            QString block4, block4_location;
            QSqlQuery block4_query("SELECT * FROM batches WHERE id = '" + students.value(16).toString() + "'", db);
            while (block4_query.next()) {
                block4 = code_to_subject[block4_query.value(1).toInt()];
                block4_location = code_to_location[block4_query.value(7).toInt()];
            }

            QString block5, block5_location;
            QSqlQuery block5_query("SELECT * FROM batches WHERE id = '" + students.value(17).toString() + "'", db);
            while (block5_query.next()) {
                block5 = code_to_subject[block5_query.value(1).toInt()];
                block5_location = code_to_location[block5_query.value(7).toInt()];
            }

            QString block6, block6_location;
            QSqlQuery block6_query("SELECT * FROM batches WHERE id = '" + students.value(18).toString() + "'", db);
            while (block6_query.next()) {
                block6 = code_to_subject[block6_query.value(1).toInt()];
                block6_location = code_to_location[block6_query.value(7).toInt()];
            }

            QString tok, tok_location;
            if (tok_block == "7") {
                QSqlQuery tok_query("SELECT * FROM batches WHERE id = '" + students.value(19).toString() + "'", db);
                tok_query.next();
                tok = code_to_subject[tok_query.value(1).toInt()];
                tok_location = code_to_location[tok_query.value(7).toInt()];
            } else {
                QSqlQuery tok_query("SELECT * FROM batches WHERE id = '" + students.value(20).toString() + "'", db);
                tok_query.next();
                tok = code_to_subject[tok_query.value(1).toInt()];
                tok_location = code_to_location[tok_query.value(7).toInt()];
            }

            html =
            "<style>"
                "td {"
                    "font-size: 10pt;"
                    "text-align: center;"
                    "vertical-align: middle;"
                    "padding-top: 10;"
                    "padding-left: 4;"
                    "padding-right: 4;"
                    "padding-bottom: 10;"
                    "position: relative"
                "}"
                ".location {"
                    "font-size: 6pt;"
                "}"
            "</style>"
            "<table border='1' style='border-collapse: collapse; border-color: black'>"
                "<tr>"
                    "<td colspan='8'><h1 align=center>TIMETABLE</h1></td>"
                "</tr>"
                "<tr>"
                    "<td width='67'></td>"
                    "<td width='112'><strong>1</strong></td>"
                    "<td width='112'><strong>2</strong></td>"
                    "<td width='112'><strong>3</strong></td>"
                    "<td width='112'><strong>4</strong></td>"
                    "<td width='56'><strong>5</strong></td>"
                    "<td width='56'><strong>6</strong></td>"
                    "<td width='112'><strong>7</strong></td>"
                "</tr>"
                "<tr>"
                    "<td></td>"
                    "<td><strong>08:30 - 09:30</strong></td>"
                    "<td><strong>09:30 - 10:30</strong></td>"
                    "<td><strong>11:00 - 12:00</strong></td>"
                    "<td><strong>12:00 - 1:00</strong></td>"
                    "<td><strong>1:30 - 2:15</strong></td>"
                    "<td><strong>2:15 - 3:00</strong></td>"
                    "<td><strong>3:00 - 4:00</strong></td>"
                "</tr>"
                "<tr>"
                    "<td>Monday</td>"
                    "<td>" + block5 +
                        "<div class='location'>" + block5_location + "</div>"
                    "</td>"
                    "<td>" + block6 +
                        "<div class='location'>" + block6_location + "</div>"
                    "</td>"
                    "<td>" + block4 +
                        "<div class='location'>" + block4_location + "</div>"
                    "</td>"
                    "<td>" + block2 +
                        "<div class='location'>" + block2_location + "</div>"
                    "</td>"
                    "<td colspan='2'>" + block1 +
                        "<div class='location'>" + block1_location + "</div>"
                    "</td>"
                    "<td></td>"
                "</tr>"
                "<tr>"
                    "<td>Tuesday</td>"
                    "<td>" + (tok_block == "7" ? tok + "<div class='location'>" + tok_location + "</div>" : "OPEN") +
                    "</td>"
                    "<td>" + (tok_block == "8" ? tok + "<div class='location'>" + tok_location + "</div>" : "OPEN") +
                    "</td>"
                    "<td>" + block6 +
                        "<div class='location'>" + block6_location + "</div>"
                    "</td>"
                    "<td>" + block4 +
                        "<div class='location'>" + block4_location + "</div>"
                    "</td>"
                    "<td colspan='2'>" + block3 +
                        "<div class='location'>" + block3_location + "</div>"
                    "</td>"
                    "<td>CAS</td>"
                "</tr>"
                "<tr>"
                    "<td>Wednesday</td>"
                    "<td>" + block2 +
                        "<div class='location'>" + block2_location + "</div>"
                    "</td>"
                    "<td>" + block5 +
                        "<div class='location'>" + block5_location + "</div>"
                    "</td>"
                    "<td>" + block3 +
                        "<div class='location'>" + block3_location + "</div>"
                    "</td>"
                    "<td>" + block6 +
                        "<div class='location'>" + block6_location + "</div>"
                    "</td>"
                    "<td colspan='2'>" + block1 +
                        "<div class='location'>" + block1_location + "</div>"
                    "</td>"
                    "<td></td>"
                "</tr>"
                "<tr>"
                    "<td>Thursday</td>"
                    "<td>" + block4 +
                        "<div class='location'>" + block4_location + "</div>"
                    "</td>"
                    "<td>OPEN</td>"
                    "<td>" + block2 +
                        "<div class='location'>" + block2_location + "</div>"
                    "</td>"
                    "<td>" + block5 +
                        "<div class='location'>" + block5_location + "</div>"
                    "</td>"
                    "<td colspan='2'>" + block3 +
                        "<div class='location'>" + block3_location + "</div>"
                    "</td>"
                    "<td></td>"
                "</tr>"
                "<tr>"
                    "<td>Friday</td>"
                    "<td>" + (tok_block == "8" ? tok + "<div class='location'>" + tok_location + "</div>" : "OPEN") +
                    "</td>"
                    "<td>" + (tok_block == "7" ? tok + "<div class='location'>" + tok_location + "</div>" : "OPEN") +
                    "</td>"
                    "<td>" + block1 +
                        "<div class='location'>" + block1_location + "</div>"
                    "</td>"
                    "<td>" + block2 +
                        "<div class='location'>" + block2_location + "</div>"
                    "</td>"
                    "<td colspan='3'>CAS</td>"
                "</tr>"
            "</table>";

            QString full_name = students.value(3).toString() != "" ? students.value(2).toString() + " " + students.value(3).toString() + " " + students.value(4).toString() : students.value(2).toString() + " " + students.value(4).toString();

            document.setHtml(html);
            printer.setOutputFileName(path + "/Students/" + full_name + ".pdf");
            printer.setPageOrientation(QPageLayout::Landscape);
            document.print(&printer);

            counter++;
            emit downloadProgress(counter, total);
        }

        teachers.exec("SELECT * FROM teachers");
        while (teachers.next()) {
            QString block1, block1_location, block1_grade;
            if (teachers.value(3).toString() != "") {
                QSqlQuery block1_query("SELECT * FROM batches WHERE id = '" + teachers.value(3).toString() + "'", db);
                block1_query.next();
                block1 = code_to_subject[block1_query.value(1).toInt()];
                block1_location = code_to_location[block1_query.value(7).toInt()];
                block1_grade = block1_query.value(5).toString();
            }

            QString block2, block2_location, block2_grade;
            if (teachers.value(4).toString() != "") {
                QSqlQuery block2_query("SELECT * FROM batches WHERE id = '" + teachers.value(4).toString() + "'", db);
                block2_query.next();
                block2 = code_to_subject[block2_query.value(1).toInt()];
                block2_location = code_to_location[block2_query.value(7).toInt()];
                block2_grade = block2_query.value(5).toString();
            }

            QString block3, block3_location, block3_grade;
            if (teachers.value(5).toString() != "") {
                QSqlQuery block3_query("SELECT * FROM batches WHERE id = '" + teachers.value(5).toString() + "'", db);
                block3_query.next();
                block3 = code_to_subject[block3_query.value(1).toInt()];
                block3_location = code_to_location[block3_query.value(7).toInt()];
                block3_grade = block3_query.value(5).toString();
            }

            QString block4, block4_location, block4_grade;
            if (teachers.value(6).toString() != "") {
                QSqlQuery block4_query("SELECT * FROM batches WHERE id = '" + teachers.value(6).toString() + "'", db);
                block4_query.next();
                block4 = code_to_subject[block4_query.value(1).toInt()];
                block4_location = code_to_location[block4_query.value(7).toInt()];
                block4_grade = block4_query.value(5).toString();
            }

            QString block5, block5_location, block5_grade;
            if (teachers.value(7).toString() != "") {
                QSqlQuery block5_query("SELECT * FROM batches WHERE id = '" + teachers.value(7).toString() + "'", db);
                block5_query.next();
                block5 = code_to_subject[block5_query.value(1).toInt()];
                block5_location = code_to_location[block5_query.value(7).toInt()];
                block5_grade = block5_query.value(5).toString();
            }

            QString block6, block6_location, block6_grade;
            if (teachers.value(8).toString() != "") {
                QSqlQuery block6_query("SELECT * FROM batches WHERE id = '" + teachers.value(8).toString() + "'", db);
                block6_query.next();
                block6 = code_to_subject[block6_query.value(1).toInt()];
                block6_location = code_to_location[block6_query.value(7).toInt()];
                block6_grade = block6_query.value(5).toString();
            }

            QString block7, block7_location, block7_grade;
            if (teachers.value(9).toString() != "") {
                QSqlQuery block7_query("SELECT * FROM batches WHERE id = '" + teachers.value(9).toString() + "'", db);
                block7_query.next();
                block7 = code_to_subject[block7_query.value(1).toInt()];
                block7_location = code_to_location[block7_query.value(7).toInt()];
                block7_grade = block7_query.value(5).toString();
            }

            QString block8, block8_location, block8_grade;
            if (teachers.value(10).toString() != "") {
                QSqlQuery block8_query("SELECT * FROM batches WHERE id = '" + teachers.value(10).toString() + "'", db);
                block8_query.next();
                block8 = code_to_subject[block8_query.value(1).toInt()];
                block8_location = code_to_location[block8_query.value(7).toInt()];
                block8_grade = block8_query.value(5).toString();
            }

            html =
            "<style>"
                "td {"
                    "font-size: 10pt;"
                    "text-align: center;"
                    "vertical-align: middle;"
                    "padding-top: 10;"
                    "padding-bottom: 10;"
                    "position: relative"
                "}"
                ".location {"
                    "font-size: 6pt;"
                "}"
            "</style>"
            "<table border='1' style='border-collapse: collapse; border-color: black'>"
                "<tr>"
                    "<td colspan='8'><h1 align=center>TIMETABLE</h1></td>"
                "</tr>"
                "<tr>"
                    "<td width='67'></td>"
                    "<td width='112'><strong>1</strong></td>"
                    "<td width='112'><strong>2</strong></td>"
                    "<td width='112'><strong>3</strong></td>"
                    "<td width='112'><strong>4</strong></td>"
                    "<td width='56'><strong>5</strong></td>"
                    "<td width='56'><strong>6</strong></td>"
                    "<td width='112'><strong>7</strong></td>"
                "</tr>"
                "<tr>"
                    "<td></td>"
                    "<td><strong>08:30 - 09:30</strong></td>"
                    "<td><strong>09:30 - 10:30</strong></td>"
                    "<td><strong>11:00 - 12:00</strong></td>"
                    "<td><strong>12:00 - 1:00</strong></td>"
                    "<td><strong>1:30 - 2:15</strong></td>"
                    "<td><strong>2:15 - 3:00</strong></td>"
                    "<td><strong>3:00 - 4:00</strong></td>"
                "</tr>"
                "<tr>"
                    "<td>Monday</td>"
                    "<td>" + (block5 != "" ? block5 + "<div class='location'>G" + block5_grade + " " + block5_location + " Block 5</div>" : "FREE") + "</td>"
                    "<td>" + (block6 != "" ? block6 + "<div class='location'>G" + block6_grade + " " + block6_location + " Block 6</div>" : "FREE") + "</td>"
                    "<td>" + (block4 != "" ? block4 + "<div class='location'>G" + block4_grade + " " + block4_location + " Block 4</div>" : "FREE") + "</td>"
                    "<td>" + (block2 != "" ? block2 + "<div class='location'>G" + block2_grade + " " + block2_location + " Block 2</div>" : "FREE") + "</td>"
                    "<td colspan='2'>" + (block1 != "" ? block1 + "<div class='location'>G" + block1_grade + " " + block1_location + " Block 1</div>" : "FREE") + "</td>"
                    "<td></td>"
                "</tr>"
                "<tr>"
                    "<td>Tuesday</td>"
                    "<td>" + (block7 != "" ? block7 + "<div class='location'>G" + block7_grade + " " + block7_location + " Block 7</div>" : "FREE") + "</td>"
                    "<td>" + (block8 != "" ? block8 + "<div class='location'>G" + block8_grade + " " + block8_location + " Block 8</div>" : "FREE") + "</td>"
                    "<td>" + (block6 != "" ? block6 + "<div class='location'>G" + block6_grade + " " + block6_location + " Block 6</div>" : "FREE") + "</td>"
                    "<td>" + (block4 != "" ? block4 + "<div class='location'>G" + block4_grade + " " + block4_location + " Block 4</div>" : "FREE") + "</td>"
                    "<td colspan='2'>" + (block3 != "" ? block3 + "<div class='location'>G" + block3_grade + " " + block3_location + " Block 3</div>" : "FREE") + "</td>"
                    "<td></td>"
                "</tr>"
                "<tr>"
                    "<td>Wednesday</td>"
                    "<td>" + (block2 != "" ? block2 + "<div class='location'>G" + block2_grade + " " + block2_location + " Block 2</div>" : "FREE") + "</td>"
                    "<td>" + (block5 != "" ? block5 + "<div class='location'>G" + block5_grade + " " + block5_location + " Block 5</div>" : "FREE") + "</td>"
                    "<td>" + (block3 != "" ? block3 + "<div class='location'>G" + block3_grade + " " + block3_location + " Block 3</div>" : "FREE") + "</td>"
                    "<td>" + (block6 != "" ? block6 + "<div class='location'>G" + block6_grade + " " + block6_location + " Block 6</div>" : "FREE") + "</td>"
                    "<td colspan='2'>" + (block1 != "" ? block1 + "<div class='location'>G" + block1_grade + " " + block1_location + " Block 1</div>" : "FREE") + "</td>"
                    "<td></td>"
                "</tr>"
                "<tr>"
                    "<td>Thursday</td>"
                    "<td>" + (block4 != "" ? block4 + "<div class='location'>G" + block4_grade + " " + block4_location + " Block 4</div>" : "FREE") + "</td>"
                    "<td>OPEN</td>"
                    "<td>" + (block2 != "" ? block2 + "<div class='location'>G" + block2_grade + " " + block2_location + " Block 2</div>" : "FREE") + "</td>"
                    "<td>" + (block5 != "" ? block5 + "<div class='location'>G" + block5_grade + " " + block5_location + " Block 5</div>" : "FREE") + "</td>"
                    "<td colspan='2'>" + (block3 != "" ? block3 + "<div class='location'>G" + block3_grade + " " + block3_location + " Block 3</div>" : "FREE") + "</td>"
                    "<td></td>"
                "</tr>"
                "<tr>"
                    "<td>Friday</td>"
                    "<td>" + (block8 != "" ? block8 + "<div class='location'>G" + block8_grade + " " + block8_location + " Block 8</div>" : "FREE") + "</td>"
                    "<td>" + (block7 != "" ? block7 + "<div class='location'>G" + block7_grade + " " + block7_location + " Block 7</div>" : "FREE") + "</td>"
                    "<td>" + (block1 != "" ? block1 + "<div class='location'>G" + block1_grade + " " + block1_location + " Block 1</div>" : "FREE") + "</td>"
                    "<td>" + (block2 != "" ? block2 + "<div class='location'>G" + block2_grade + " " + block2_location + " Block 2</div>" : "FREE") + "</td>"
                    "<td colspan='2'></td>"
                    "<td></td>"
                "</tr>"
            "</table>";

            document.setHtml(html);
            printer.setOutputFileName(path + "/Teachers/" + teachers.value(1).toString() + ".pdf");
            printer.setPageOrientation(QPageLayout::Landscape);
            document.print(&printer);

            counter++;
            emit downloadProgress(counter, total);
        }
    });
}

QString Database::initials(QString string)
{
    QString final;
    for (QString word : string.split(" "))
        final.append(word.at(0));
    return final;
}

void Database::initDatabase()
{

    QFileInfo check_file("../Databases/db.sqlite");
    if (!check_file.exists() || !check_file.isFile()) {
        QDir().mkdir("../Databases");
    }

    db = QSqlDatabase::database();

    QSqlQuery query;

    query.exec("CREATE TABLE IF NOT EXISTS students ("
               "reg integer primary key, "
               "edu text, "
               "first_name text, "
               "middle_name text, "
               "last_name text, "
               "gender text, "
               "grade integer, "
               "hl_subject_1 text, "
               "hl_subject_2 text, "
               "hl_subject_3 text, "
               "sl_subject_1 text, "
               "sl_subject_2 text, "
               "sl_subject_3 text, "
               "block_1 text, "
               "block_2 text, "
               "block_3 text, "
               "block_4 text, "
               "block_5 text, "
               "block_6 text, "
               "block_7 text)");

    query.exec("CREATE TABLE IF NOT EXISTS subjects ("
               "id text primary key, "
               "name text, "
               "teachers text, "
               "batches text)");

    query.exec("CREATE TABLE IF NOT EXISTS teachers ("
               "id text primary key, "
               "name text, "
               "subjects text, "
               "block_1 text, "
               "block_2 text, "
               "block_3 text, "
               "block_4 text, "
               "block_5 text, "
               "block_6 text, "
               "block_7 text)");

    query.exec("CREATE TABLE IF NOT EXISTS batches ("
               "id integer primary key, "
               "subject text, "
               "level text, "
               "block int, "
               "teacher text, "
               "grade int, "
               "students text)");

    query.exec("CREATE TABLE IF NOT EXISTS grades ("
               "id integer primary key, "
               "assigned integer, "
               "tok integer)");
    query.exec("INSERT INTO grades (id, assigned, tok) VALUES(11, 0, 7)");
    query.exec("INSERT INTO grades (id, assigned, tok) VALUES(12, 0, 8)");

    query.exec("CREATE TABLE IF NOT EXISTS locations ("
               "id integer primary key, "
               "name text, "
               "block_1 text, "
               "block_2 text, "
               "block_3 text, "
               "block_4 text, "
               "block_5 text, "
               "block_6 text, "
               "block_7 text)");

    QStringList codes;
    codes.append("ALV");
    codes.append("ANA");
    codes.append("APU");
    codes.append("ASH");
    codes.append("BIS");
    codes.append("BIP");
    codes.append("CAR");
    codes.append("CHA");
    codes.append("DAN");
    codes.append("DEE");
    codes.append("ERW");
    codes.append("FRA");
    codes.append("GEO");
    codes.append("GUR");
    codes.append("HAR");
    codes.append("JUL");
    codes.append("KAV");
    codes.append("KAR");
    codes.append("LOR");
    codes.append("LOV");
    codes.append("MAD");
    codes.append("MAH");
    codes.append("MAL");
    codes.append("MAK");
    codes.append("MAS");
    codes.append("MEL");
    codes.append("NAO");
    codes.append("NAR");
    codes.append("NEE");
    codes.append("NIL");
    codes.append("NIS");
    codes.append("PRE");
    codes.append("PRI");
    codes.append("RAD");
    codes.append("RAJ");
    codes.append("RAS");
    codes.append("RIC");
    codes.append("SAN");
    codes.append("SAS");
    codes.append("SAP");
    codes.append("SHA");
    codes.append("SHG");
    codes.append("SHS");
    codes.append("SHE");
    codes.append("SHR");
    codes.append("SIN");
    codes.append("SOM");
    codes.append("SON");
    codes.append("SRE");
    codes.append("SUR");
    codes.append("SUV");
    codes.append("SWA");
    codes.append("TAN");
    codes.append("THE");
    codes.append("UMA");
    codes.append("UTK");
    codes.append("VAG");

    QStringList teachers;
    teachers.append("Mr. Alvaro Duran");
    teachers.append("Ms. Anandita Dutta");
    teachers.append("Mrs. Apurva Sarkar");
    teachers.append("Mr. Ashis Sannigrahi");
    teachers.append("Mr. Bipin Shah");
    teachers.append("Mr. Bipul Pande");
    teachers.append("Ms. Carolina Mondragon");
    teachers.append("Ms. Chandana Ghosh");
    teachers.append("Mr. Daniel Ngatia");
    teachers.append("Ms. Deepti Vimal");
    teachers.append("Mr. Erwin Utchanah");
    teachers.append("Mr. Francis Kimwell");
    teachers.append("Mr. George Juma");
    teachers.append("Ms. Gursheen Ghuman");
    teachers.append("Mr. Harry Martin");
    teachers.append("Mr. Julian Vera Augilar");
    teachers.append("Ms. Kavita Dyas");
    teachers.append("Ms. Kavita Rajput");
    teachers.append("Ms. Lorraine Rodrigues");
    teachers.append("Ms. Loveena Figueredo");
    teachers.append("Ms. Madhulika Pande");
    teachers.append("Ms. Mahua Sengupta");
    teachers.append("Ms. Malvika Deo");
    teachers.append("Mr. Manoj Kumar");
    teachers.append("Ms. Mansi Sawant");
    teachers.append("Ms. Melina Gavaloo");
    teachers.append("Mr. Naoufel Ben Fredj");
    teachers.append("Mr. Narender Dalal");
    teachers.append("Ms. Neera Tahilramaney");
    teachers.append("Mr. Nilendu Deb");
    teachers.append("Ms. Nisha Maniar");
    teachers.append("Ms. Premalatha Shrinath");
    teachers.append("Ms. Pritha Mukherjee");
    teachers.append("Ms. Rajanigandha Deshmukh");
    teachers.append("Mr. Rajiv Jha");
    teachers.append("Mrs. Rashmi Baruah");
    teachers.append("Ms. Richa Anand");
    teachers.append("Ms. Sanika Vaze");
    teachers.append("Mr. Sanjeev Sahni");
    teachers.append("Mr. Sapan Pal");
    teachers.append("Ms. Shabari Kar");
    teachers.append("Mrs. Shalini Ghosh");
    teachers.append("Ms. Shama Shaikh");
    teachers.append("Ms. Sheetal Daver");
    teachers.append("Mr. Shrikant Puranik");
    teachers.append("Ms. Sindhuja Malladi");
    teachers.append("Ms. Soma Basu");
    teachers.append("Ms. Sonali Bajaj");
    teachers.append("Mr. Sreeraman Ramanathan");
    teachers.append("Mr. Suresh Wadhiya");
    teachers.append("Mr. Suvash Dhakal");
    teachers.append("Ms. Swarnalatha Potukuchi");
    teachers.append("Ms. Tannistha Chaterjee");
    teachers.append("Ms. Theresa Thomas");
    teachers.append("Dr. Uma Shivayogimath");
    teachers.append("Mr. Utkarsh Kumar");
    teachers.append("Ms. Vagisha Srivastava");

    QList<QStringList> subs;
    subs.append(QStringList() << "spn ab" << "spn b");
    subs.append(QStringList() << "langlit");
    subs.append(QStringList() << "phy");
    subs.append(QStringList() << "ai");
    subs.append(QStringList() << "langlit" << "tok");
    subs.append(QStringList() << "phy");
    subs.append(QStringList() << "spn b");
    subs.append(QStringList() << "phy");
    subs.append(QStringList() << "bio");
    subs.append(QStringList() << "bio");
    subs.append(QStringList() << "tok");
    subs.append(QStringList() << "geog");
    subs.append(QStringList() << "theatre");
    subs.append(QStringList() << "spn ab");
    subs.append(QStringList() << "sehs");
    subs.append(QStringList() << "spn ab");
    subs.append(QStringList() << "psych" << "tok");
    subs.append(QStringList() << "aa");
    subs.append(QStringList() << "langlit" << "tok");
    subs.append(QStringList() << "sehs");
    subs.append(QStringList() << "hindi b");
    subs.append(QStringList() << "langlit" << "tok");
    subs.append(QStringList() << "tok");
    subs.append(QStringList() << "bm");
    subs.append(QStringList() << "bio");
    subs.append(QStringList() << "langlit" << "lit");
    subs.append(QStringList() << "fre b");
    subs.append(QStringList() << "tok");
    subs.append(QStringList() << "chem");
    subs.append(QStringList() << "comp sci");
    subs.append(QStringList() << "langlit");
    subs.append(QStringList() << "chem");
    subs.append(QStringList() << "gl politics");
    subs.append(QStringList() << "fre b" << "tok");
    subs.append(QStringList() << "aa");
    subs.append(QStringList() << "eco");
    subs.append(QStringList() << "langlit");
    subs.append(QStringList() << "fre ab");
    subs.append(QStringList() << "aa");
    subs.append(QStringList() << "aa");
    subs.append(QStringList() << "psych");
    subs.append(QStringList() << "chem");
    subs.append(QStringList() << "eco");
    subs.append(QStringList() << "ai");
    subs.append(QStringList() << "vis arts");
    subs.append(QStringList() << "eco");
    subs.append(QStringList() << "bio");
    subs.append(QStringList() << "bm");
    subs.append(QStringList() << "hindi b");
    subs.append(QStringList() << "chem");
    subs.append(QStringList() << "eco");
    subs.append(QStringList() << "hist" << "tok");
    subs.append(QStringList() << "geog");
    subs.append(QStringList() << "vis arts");
    subs.append(QStringList() << "aa");
    subs.append(QStringList() << "phy");
    subs.append(QStringList() << "langlit");

    query.exec("SELECT COUNT(id) FROM locations");
    query.next();
    if (query.value(0).toInt() == 0) {
        QList<QString> locations = QList<QString>({"LR7A", "LR7B", "LR7C", "LR7D", "LR6D", "LR6E", "LR6F", "LR6G", "LR6H", "ML", "CL1", "CL2", "LCSA", "SSL", "PL1", "PL2", "BL1", "BL2", "LR4A", "LR4B", "CL", "BB", "SA", "LIB", "AR1", "AR2", "9A", "9B", "9C", "8A", "8B", "8C", "10A", "10B", "10C"});
        for (QString location : locations)
            query.exec("INSERT INTO locations (name, block_1, block_2, block_3, block_4, block_5, block_6, block_7, block_8) VALUES ('" + location + "', '', '', '', '', '', '', '', '')");
    }
}

int Database::get_student(int id)
{
    for (int i = 0; i < all_students.length(); i++) {
        if (all_students[i].reg == id) {
            return i;
        }
    }
}

int Database::get_remaining_student(int id)
{
    for (int i = 0; i < remaining_students.length(); i++) {
        if (remaining_students[i].reg == id) {
            return i;
        }
    }
}

int Database::get_subject(int id)
{
    for (int i = 0; i < all_subjects.length(); i++) {
        if (all_subjects[i].id == id) {
            return i;
        }
    }
}

int Database::get_teacher(int id)
{
    for (int i = 0; i < all_teachers.length(); i++) {
        if (all_teachers[i].id == id) {
            return i;
        }
    }
}

int Database::get_batch(QString id)
{
    for (int i = 0; i < all_batches.length(); i++) {
        if (all_batches[i].id == id) {
            return i;
        }
    }
}

int Database::get_batch_by_block(QString id, int block)
{
    for (int i = 0; i < all_batches_by_block["block_" + QVariant(block).toString()].length(); i++) {
        if (all_batches_by_block["block_" + QVariant(block).toString()][i].id == id) {
            return i;
        }
    }
}

QString Database::create_batch_id()
{
    QString chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}:<>?|-=[]:,./";
    QString id = "";
    for (int i = 0; i < 20; i ++) {
        id += chars.mid(qFloor(QRandomGenerator::global()->generateDouble() * 90), 1);
    }
    return id;
}

QString Database::qListIntToQString(QList<int> list)
{
    QString string = "";
    for (int value : list) {
        string.append(QVariant(value).toString() + ", ");
    }

    return string.mid(0, string.length() - 2);
}

int Database::binary_search(int key, QList<int> list)
{
    int left = 0;
    int right = list.length() - 1;

    if (left > right)
        return -1;

    int mid = round((left + right) / 2);
    if (key == list[mid]) {
        return mid;
    } else if (key < list[mid]) {
        return binary_search(key, list.mid(left, mid - 1));
    } else { // key > list[mid]
        return binary_search(key, list.mid(mid + 1, right));
    }
}
