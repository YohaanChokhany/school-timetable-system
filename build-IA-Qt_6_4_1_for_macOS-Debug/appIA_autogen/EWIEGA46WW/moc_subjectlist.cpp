/****************************************************************************
** Meta object code from reading C++ file 'subjectlist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../IA/subjectlist.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subjectlist.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_SubjectList_t {
    uint offsetsAndSizes[44];
    char stringdata0[12];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[15];
    char stringdata5[6];
    char stringdata6[16];
    char stringdata7[14];
    char stringdata8[3];
    char stringdata9[5];
    char stringdata10[5];
    char stringdata11[9];
    char stringdata12[8];
    char stringdata13[14];
    char stringdata14[15];
    char stringdata15[11];
    char stringdata16[9];
    char stringdata17[15];
    char stringdata18[6];
    char stringdata19[13];
    char stringdata20[11];
    char stringdata21[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SubjectList_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SubjectList_t qt_meta_stringdata_SubjectList = {
    {
        QT_MOC_LITERAL(0, 11),  // "SubjectList"
        QT_MOC_LITERAL(12, 15),  // "preItemAppended"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 16),  // "postItemAppended"
        QT_MOC_LITERAL(46, 14),  // "preItemRemoved"
        QT_MOC_LITERAL(61, 5),  // "index"
        QT_MOC_LITERAL(67, 15),  // "postItemRemoved"
        QT_MOC_LITERAL(83, 13),  // "appendSubject"
        QT_MOC_LITERAL(97, 2),  // "id"
        QT_MOC_LITERAL(100, 4),  // "code"
        QT_MOC_LITERAL(105, 4),  // "name"
        QT_MOC_LITERAL(110, 8),  // "teachers"
        QT_MOC_LITERAL(119, 7),  // "batches"
        QT_MOC_LITERAL(127, 13),  // "clearSubjects"
        QT_MOC_LITERAL(141, 14),  // "removeSubjects"
        QT_MOC_LITERAL(156, 10),  // "QList<int>"
        QT_MOC_LITERAL(167, 8),  // "subjects"
        QT_MOC_LITERAL(176, 14),  // "searchSubjects"
        QT_MOC_LITERAL(191, 5),  // "query"
        QT_MOC_LITERAL(197, 12),  // "loadSubjects"
        QT_MOC_LITERAL(210, 10),  // "getSubject"
        QT_MOC_LITERAL(221, 7)   // "subject"
    },
    "SubjectList",
    "preItemAppended",
    "",
    "postItemAppended",
    "preItemRemoved",
    "index",
    "postItemRemoved",
    "appendSubject",
    "id",
    "code",
    "name",
    "teachers",
    "batches",
    "clearSubjects",
    "removeSubjects",
    "QList<int>",
    "subjects",
    "searchSubjects",
    "query",
    "loadSubjects",
    "getSubject",
    "subject"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SubjectList[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,
       4,    1,   76,    2, 0x06,    3 /* Public */,
       6,    0,   79,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    5,   80,    2, 0x0a,    6 /* Public */,
      13,    0,   91,    2, 0x0a,   12 /* Public */,
      14,    1,   92,    2, 0x0a,   13 /* Public */,
      17,    1,   95,    2, 0x0a,   15 /* Public */,
      19,    0,   98,    2, 0x0a,   17 /* Public */,
      20,    1,   99,    2, 0x0a,   18 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::QStringList, 0x80000000 | 15,   21,

       0        // eod
};

Q_CONSTINIT const QMetaObject SubjectList::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SubjectList.offsetsAndSizes,
    qt_meta_data_SubjectList,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_SubjectList_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SubjectList, std::true_type>,
        // method 'preItemAppended'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'postItemAppended'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'preItemRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'postItemRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'appendSubject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clearSubjects'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeSubjects'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>,
        // method 'searchSubjects'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'loadSubjects'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getSubject'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>
    >,
    nullptr
} };

void SubjectList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SubjectList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->preItemRemoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->postItemRemoved(); break;
        case 4: _t->appendSubject((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 5: _t->clearSubjects(); break;
        case 6: _t->removeSubjects((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 7: _t->searchSubjects((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->loadSubjects(); break;
        case 9: { QStringList _r = _t->getSubject((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SubjectList::*)();
            if (_t _q_method = &SubjectList::preItemAppended; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SubjectList::*)();
            if (_t _q_method = &SubjectList::postItemAppended; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SubjectList::*)(int );
            if (_t _q_method = &SubjectList::preItemRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SubjectList::*)();
            if (_t _q_method = &SubjectList::postItemRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *SubjectList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SubjectList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SubjectList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SubjectList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SubjectList::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SubjectList::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SubjectList::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SubjectList::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
