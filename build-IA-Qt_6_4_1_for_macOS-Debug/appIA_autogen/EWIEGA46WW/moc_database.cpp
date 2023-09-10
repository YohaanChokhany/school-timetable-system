/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../IA/database.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Database_t {
    uint offsetsAndSizes[162];
    char stringdata0[9];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[17];
    char stringdata5[6];
    char stringdata6[12];
    char stringdata7[12];
    char stringdata8[13];
    char stringdata9[10];
    char stringdata10[9];
    char stringdata11[9];
    char stringdata12[8];
    char stringdata13[16];
    char stringdata14[11];
    char stringdata15[5];
    char stringdata16[11];
    char stringdata17[4];
    char stringdata18[4];
    char stringdata19[11];
    char stringdata20[12];
    char stringdata21[10];
    char stringdata22[7];
    char stringdata23[6];
    char stringdata24[4];
    char stringdata25[4];
    char stringdata26[4];
    char stringdata27[4];
    char stringdata28[4];
    char stringdata29[4];
    char stringdata30[12];
    char stringdata31[11];
    char stringdata32[5];
    char stringdata33[11];
    char stringdata34[9];
    char stringdata35[12];
    char stringdata36[3];
    char stringdata37[11];
    char stringdata38[9];
    char stringdata39[12];
    char stringdata40[11];
    char stringdata41[9];
    char stringdata42[11];
    char stringdata43[11];
    char stringdata44[9];
    char stringdata45[18];
    char stringdata46[15];
    char stringdata47[16];
    char stringdata48[9];
    char stringdata49[7];
    char stringdata50[19];
    char stringdata51[15];
    char stringdata52[13];
    char stringdata53[18];
    char stringdata54[5];
    char stringdata55[20];
    char stringdata56[17];
    char stringdata57[10];
    char stringdata58[6];
    char stringdata59[23];
    char stringdata60[13];
    char stringdata61[8];
    char stringdata62[28];
    char stringdata63[31];
    char stringdata64[13];
    char stringdata65[6];
    char stringdata66[15];
    char stringdata67[8];
    char stringdata68[14];
    char stringdata69[15];
    char stringdata70[20];
    char stringdata71[12];
    char stringdata72[22];
    char stringdata73[12];
    char stringdata74[10];
    char stringdata75[19];
    char stringdata76[12];
    char stringdata77[16];
    char stringdata78[18];
    char stringdata79[14];
    char stringdata80[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Database_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Database_t qt_meta_stringdata_Database = {
    {
        QT_MOC_LITERAL(0, 8),  // "Database"
        QT_MOC_LITERAL(9, 8),  // "progress"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 6),  // "epochs"
        QT_MOC_LITERAL(26, 16),  // "downloadProgress"
        QT_MOC_LITERAL(43, 5),  // "total"
        QT_MOC_LITERAL(49, 11),  // "getSubjects"
        QT_MOC_LITERAL(61, 11),  // "getStudents"
        QT_MOC_LITERAL(73, 12),  // "search_query"
        QT_MOC_LITERAL(86, 9),  // "loginUser"
        QT_MOC_LITERAL(96, 8),  // "username"
        QT_MOC_LITERAL(105, 8),  // "password"
        QT_MOC_LITERAL(114, 7),  // "addUser"
        QT_MOC_LITERAL(122, 15),  // "confirmPassword"
        QT_MOC_LITERAL(138, 10),  // "uploadFile"
        QT_MOC_LITERAL(149, 4),  // "path"
        QT_MOC_LITERAL(154, 10),  // "addStudent"
        QT_MOC_LITERAL(165, 3),  // "reg"
        QT_MOC_LITERAL(169, 3),  // "edu"
        QT_MOC_LITERAL(173, 10),  // "first_name"
        QT_MOC_LITERAL(184, 11),  // "middle_name"
        QT_MOC_LITERAL(196, 9),  // "last_name"
        QT_MOC_LITERAL(206, 6),  // "gender"
        QT_MOC_LITERAL(213, 5),  // "grade"
        QT_MOC_LITERAL(219, 3),  // "hl1"
        QT_MOC_LITERAL(223, 3),  // "hl2"
        QT_MOC_LITERAL(227, 3),  // "hl3"
        QT_MOC_LITERAL(231, 3),  // "sl1"
        QT_MOC_LITERAL(235, 3),  // "sl2"
        QT_MOC_LITERAL(239, 3),  // "sl3"
        QT_MOC_LITERAL(243, 11),  // "editStudent"
        QT_MOC_LITERAL(255, 10),  // "addTeacher"
        QT_MOC_LITERAL(266, 4),  // "name"
        QT_MOC_LITERAL(271, 10),  // "QList<int>"
        QT_MOC_LITERAL(282, 8),  // "subjects"
        QT_MOC_LITERAL(291, 11),  // "editTeacher"
        QT_MOC_LITERAL(303, 2),  // "id"
        QT_MOC_LITERAL(306, 10),  // "addSubject"
        QT_MOC_LITERAL(317, 8),  // "teachers"
        QT_MOC_LITERAL(326, 11),  // "editSubject"
        QT_MOC_LITERAL(338, 10),  // "getStudent"
        QT_MOC_LITERAL(349, 8),  // "getBatch"
        QT_MOC_LITERAL(358, 10),  // "getSubject"
        QT_MOC_LITERAL(369, 10),  // "getTeacher"
        QT_MOC_LITERAL(380, 8),  // "getGrade"
        QT_MOC_LITERAL(389, 17),  // "verifyStudentData"
        QT_MOC_LITERAL(407, 14),  // "refreshNewYear"
        QT_MOC_LITERAL(422, 15),  // "createTimetable"
        QT_MOC_LITERAL(438, 8),  // "initials"
        QT_MOC_LITERAL(447, 6),  // "string"
        QT_MOC_LITERAL(454, 18),  // "getStudentLocation"
        QT_MOC_LITERAL(473, 14),  // "get_all_values"
        QT_MOC_LITERAL(488, 12),  // "permutations"
        QT_MOC_LITERAL(501, 17),  // "QList<QList<int>>"
        QT_MOC_LITERAL(519, 4),  // "list"
        QT_MOC_LITERAL(524, 19),  // "generate_candidates"
        QT_MOC_LITERAL(544, 16),  // "verify_candidate"
        QT_MOC_LITERAL(561, 9),  // "candidate"
        QT_MOC_LITERAL(571, 5),  // "block"
        QT_MOC_LITERAL(577, 22),  // "get_batches_from_block"
        QT_MOC_LITERAL(600, 12),  // "QList<Batch>"
        QT_MOC_LITERAL(613, 7),  // "subject"
        QT_MOC_LITERAL(621, 27),  // "calculate_optimum_candidate"
        QT_MOC_LITERAL(649, 30),  // "std::tuple<Student,QList<int>>"
        QT_MOC_LITERAL(680, 12),  // "create_batch"
        QT_MOC_LITERAL(693, 5),  // "Batch"
        QT_MOC_LITERAL(699, 14),  // "insert_student"
        QT_MOC_LITERAL(714, 7),  // "student"
        QT_MOC_LITERAL(722, 13),  // "assignBatches"
        QT_MOC_LITERAL(736, 14),  // "implementBatch"
        QT_MOC_LITERAL(751, 19),  // "implementTOKBatches"
        QT_MOC_LITERAL(771, 11),  // "get_student"
        QT_MOC_LITERAL(783, 21),  // "get_remaining_student"
        QT_MOC_LITERAL(805, 11),  // "get_subject"
        QT_MOC_LITERAL(817, 9),  // "get_batch"
        QT_MOC_LITERAL(827, 18),  // "get_batch_by_block"
        QT_MOC_LITERAL(846, 11),  // "get_teacher"
        QT_MOC_LITERAL(858, 15),  // "create_batch_id"
        QT_MOC_LITERAL(874, 17),  // "qListIntToQString"
        QT_MOC_LITERAL(892, 13),  // "binary_search"
        QT_MOC_LITERAL(906, 3)   // "key"
    },
    "Database",
    "progress",
    "",
    "epochs",
    "downloadProgress",
    "total",
    "getSubjects",
    "getStudents",
    "search_query",
    "loginUser",
    "username",
    "password",
    "addUser",
    "confirmPassword",
    "uploadFile",
    "path",
    "addStudent",
    "reg",
    "edu",
    "first_name",
    "middle_name",
    "last_name",
    "gender",
    "grade",
    "hl1",
    "hl2",
    "hl3",
    "sl1",
    "sl2",
    "sl3",
    "editStudent",
    "addTeacher",
    "name",
    "QList<int>",
    "subjects",
    "editTeacher",
    "id",
    "addSubject",
    "teachers",
    "editSubject",
    "getStudent",
    "getBatch",
    "getSubject",
    "getTeacher",
    "getGrade",
    "verifyStudentData",
    "refreshNewYear",
    "createTimetable",
    "initials",
    "string",
    "getStudentLocation",
    "get_all_values",
    "permutations",
    "QList<QList<int>>",
    "list",
    "generate_candidates",
    "verify_candidate",
    "candidate",
    "block",
    "get_batches_from_block",
    "QList<Batch>",
    "subject",
    "calculate_optimum_candidate",
    "std::tuple<Student,QList<int>>",
    "create_batch",
    "Batch",
    "insert_student",
    "student",
    "assignBatches",
    "implementBatch",
    "implementTOKBatches",
    "get_student",
    "get_remaining_student",
    "get_subject",
    "get_batch",
    "get_batch_by_block",
    "get_teacher",
    "create_batch_id",
    "qListIntToQString",
    "binary_search",
    "key"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Database[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  278,    2, 0x06,    1 /* Public */,
       4,    2,  283,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  288,    2, 0x0a,    7 /* Public */,
       7,    1,  289,    2, 0x0a,    8 /* Public */,
       9,    2,  292,    2, 0x0a,   10 /* Public */,
      12,    3,  297,    2, 0x0a,   13 /* Public */,
      14,    1,  304,    2, 0x0a,   17 /* Public */,
      16,   13,  307,    2, 0x0a,   19 /* Public */,
      30,   12,  334,    2, 0x0a,   33 /* Public */,
      31,    2,  359,    2, 0x0a,   46 /* Public */,
      35,    3,  364,    2, 0x0a,   49 /* Public */,
      37,    1,  371,    2, 0x0a,   53 /* Public */,
      37,    2,  374,    2, 0x0a,   55 /* Public */,
      39,    2,  379,    2, 0x0a,   58 /* Public */,
      40,    1,  384,    2, 0x0a,   61 /* Public */,
      41,    1,  387,    2, 0x0a,   63 /* Public */,
      42,    1,  390,    2, 0x0a,   65 /* Public */,
      43,    1,  393,    2, 0x0a,   67 /* Public */,
      44,    1,  396,    2, 0x0a,   69 /* Public */,
      45,    1,  399,    2, 0x0a,   71 /* Public */,
      46,    1,  402,    2, 0x0a,   73 /* Public */,
      47,    2,  405,    2, 0x0a,   75 /* Public */,
      48,    1,  410,    2, 0x0a,   78 /* Public */,
      50,    1,  413,    2, 0x0a,   80 /* Public */,
      51,    1,  416,    2, 0x0a,   82 /* Public */,
      52,    1,  419,    2, 0x0a,   84 /* Public */,
      55,    1,  422,    2, 0x0a,   86 /* Public */,
      56,    2,  425,    2, 0x0a,   88 /* Public */,
      59,    2,  430,    2, 0x0a,   91 /* Public */,
      62,    0,  435,    2, 0x0a,   94 /* Public */,
      64,    2,  436,    2, 0x0a,   95 /* Public */,
      66,    2,  441,    2, 0x0a,   98 /* Public */,
      68,    1,  446,    2, 0x0a,  101 /* Public */,
      69,    0,  449,    2, 0x0a,  103 /* Public */,
      70,    0,  450,    2, 0x0a,  104 /* Public */,
      71,    1,  451,    2, 0x0a,  105 /* Public */,
      72,    1,  454,    2, 0x0a,  107 /* Public */,
      73,    1,  457,    2, 0x0a,  109 /* Public */,
      74,    1,  460,    2, 0x0a,  111 /* Public */,
      75,    2,  463,    2, 0x0a,  113 /* Public */,
      76,    1,  468,    2, 0x0a,  116 /* Public */,
      77,    0,  471,    2, 0x0a,  118 /* Public */,
      78,    1,  472,    2, 0x0a,  119 /* Public */,
      79,    2,  475,    2, 0x0a,  121 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    1,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    1,    5,

 // slots: parameters
    QMetaType::QStringList,
    QMetaType::QStringList, QMetaType::QString,    8,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   17,   18,   19,   20,   21,   22,   24,   25,   26,   27,   28,   29,
    QMetaType::QString, QMetaType::QString, 0x80000000 | 33,   32,   34,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 33,   36,   32,   34,
    QMetaType::QString, QMetaType::QString,   32,
    QMetaType::QString, QMetaType::QString, QMetaType::QStringList,   32,   38,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   36,   32,
    QMetaType::QStringList, QMetaType::Int,   36,
    QMetaType::QStringList, QMetaType::QString,   36,
    QMetaType::QStringList, QMetaType::Int,   36,
    QMetaType::QStringList, QMetaType::Int,   36,
    QMetaType::QStringList, QMetaType::Int,   36,
    QMetaType::Bool, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   15,   23,
    QMetaType::QString, QMetaType::QString,   49,
    QMetaType::QStringList, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   23,
    0x80000000 | 53, 0x80000000 | 33,   54,
    0x80000000 | 53, 0x80000000 | 33,   34,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString,   57,   58,
    0x80000000 | 60, QMetaType::Int, QMetaType::Int,   61,   58,
    0x80000000 | 63,
    0x80000000 | 65, QMetaType::Int, QMetaType::Int,   61,   58,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 33,   67,   57,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,   36,
    QMetaType::Int, QMetaType::Int,   36,
    QMetaType::Int, QMetaType::Int,   36,
    QMetaType::Int, QMetaType::QString,   36,
    QMetaType::Int, QMetaType::QString, QMetaType::Int,   36,   58,
    QMetaType::Int, QMetaType::Int,   36,
    QMetaType::QString,
    QMetaType::QString, 0x80000000 | 33,   54,
    QMetaType::Int, QMetaType::Int, 0x80000000 | 33,   80,   54,

       0        // eod
};

Q_CONSTINIT const QMetaObject Database::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Database.offsetsAndSizes,
    qt_meta_data_Database,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Database_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Database, std::true_type>,
        // method 'progress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'downloadProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getSubjects'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'getStudents'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'loginUser'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addUser'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'uploadFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addStudent'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'editStudent'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addTeacher'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>,
        // method 'editTeacher'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>,
        // method 'addSubject'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addSubject'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'editSubject'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getStudent'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getBatch'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getSubject'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getTeacher'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getGrade'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'verifyStudentData'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'refreshNewYear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'createTimetable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'initials'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getStudentLocation'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_all_values'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'permutations'
        QtPrivate::TypeAndForceComplete<QList<QList<int>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>,
        // method 'generate_candidates'
        QtPrivate::TypeAndForceComplete<QList<QList<int>>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>,
        // method 'verify_candidate'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_batches_from_block'
        QtPrivate::TypeAndForceComplete<QList<Batch>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'calculate_optimum_candidate'
        QtPrivate::TypeAndForceComplete<std::tuple<Student,QList<int>>, std::false_type>,
        // method 'create_batch'
        QtPrivate::TypeAndForceComplete<Batch, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'insert_student'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>,
        // method 'assignBatches'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'implementBatch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'implementTOKBatches'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_student'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_remaining_student'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_subject'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_batch'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'get_batch_by_block'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_teacher'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'create_batch_id'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'qListIntToQString'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>,
        // method 'binary_search'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>
    >,
    nullptr
} };

void Database::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Database *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->progress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->downloadProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: { QStringList _r = _t->getSubjects();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 3: { QStringList _r = _t->getStudents((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->loginUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->addUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->uploadFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: { QString _r = _t->addStudent((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[13])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->editStudent((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->addTeacher((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->editTeacher((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->addSubject((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->addSubject((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->editSubject((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QStringList _r = _t->getStudent((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 15: { QStringList _r = _t->getBatch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 16: { QStringList _r = _t->getSubject((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 17: { QStringList _r = _t->getTeacher((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 18: { QStringList _r = _t->getGrade((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->verifyStudentData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->refreshNewYear((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->createTimetable((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 22: { QString _r = _t->initials((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QStringList _r = _t->getStudentLocation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->get_all_values((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: { QList<QList<int>> _r = _t->permutations((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QList<int>>*>(_a[0]) = std::move(_r); }  break;
        case 26: { QList<QList<int>> _r = _t->generate_candidates((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QList<int>>*>(_a[0]) = std::move(_r); }  break;
        case 27: { bool _r = _t->verify_candidate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: { QList<Batch> _r = _t->get_batches_from_block((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<Batch>*>(_a[0]) = std::move(_r); }  break;
        case 29: { std::tuple<Student,QList<int>> _r = _t->calculate_optimum_candidate();
            if (_a[0]) *reinterpret_cast< std::tuple<Student,QList<int>>*>(_a[0]) = std::move(_r); }  break;
        case 30: { Batch _r = _t->create_batch((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< Batch*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->insert_student((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[2]))); break;
        case 32: _t->assignBatches((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->implementBatch(); break;
        case 34: _t->implementTOKBatches(); break;
        case 35: { int _r = _t->get_student((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 36: { int _r = _t->get_remaining_student((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 37: { int _r = _t->get_subject((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 38: { int _r = _t->get_batch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 39: { int _r = _t->get_batch_by_block((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 40: { int _r = _t->get_teacher((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 41: { QString _r = _t->create_batch_id();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 42: { QString _r = _t->qListIntToQString((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 43: { int _r = _t->binary_search((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 42:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 43:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Database::*)(int , int );
            if (_t _q_method = &Database::progress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Database::*)(int , int );
            if (_t _q_method = &Database::downloadProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *Database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Database.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void Database::progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Database::downloadProgress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
