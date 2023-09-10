/****************************************************************************
** Meta object code from reading C++ file 'todolist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../IA/todolist.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'todolist.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ToDoList_t {
    uint offsetsAndSizes[50];
    char stringdata0[9];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[15];
    char stringdata5[6];
    char stringdata6[16];
    char stringdata7[11];
    char stringdata8[4];
    char stringdata9[4];
    char stringdata10[5];
    char stringdata11[11];
    char stringdata12[12];
    char stringdata13[10];
    char stringdata14[7];
    char stringdata15[4];
    char stringdata16[4];
    char stringdata17[4];
    char stringdata18[4];
    char stringdata19[4];
    char stringdata20[4];
    char stringdata21[11];
    char stringdata22[21];
    char stringdata23[15];
    char stringdata24[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ToDoList_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ToDoList_t qt_meta_stringdata_ToDoList = {
    {
        QT_MOC_LITERAL(0, 8),  // "ToDoList"
        QT_MOC_LITERAL(9, 15),  // "preItemAppended"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 16),  // "postItemAppended"
        QT_MOC_LITERAL(43, 14),  // "preItemRemoved"
        QT_MOC_LITERAL(58, 5),  // "index"
        QT_MOC_LITERAL(64, 15),  // "postItemRemoved"
        QT_MOC_LITERAL(80, 10),  // "appendItem"
        QT_MOC_LITERAL(91, 3),  // "reg"
        QT_MOC_LITERAL(95, 3),  // "edu"
        QT_MOC_LITERAL(99, 4),  // "name"
        QT_MOC_LITERAL(104, 10),  // "first_name"
        QT_MOC_LITERAL(115, 11),  // "middle_name"
        QT_MOC_LITERAL(127, 9),  // "last_name"
        QT_MOC_LITERAL(137, 6),  // "gender"
        QT_MOC_LITERAL(144, 3),  // "hl1"
        QT_MOC_LITERAL(148, 3),  // "hl2"
        QT_MOC_LITERAL(152, 3),  // "hl3"
        QT_MOC_LITERAL(156, 3),  // "sl1"
        QT_MOC_LITERAL(160, 3),  // "sl2"
        QT_MOC_LITERAL(164, 3),  // "sl3"
        QT_MOC_LITERAL(168, 10),  // "clearItems"
        QT_MOC_LITERAL(179, 20),  // "removeCompletedItems"
        QT_MOC_LITERAL(200, 14),  // "searchStudents"
        QT_MOC_LITERAL(215, 5)   // "query"
    },
    "ToDoList",
    "preItemAppended",
    "",
    "postItemAppended",
    "preItemRemoved",
    "index",
    "postItemRemoved",
    "appendItem",
    "reg",
    "edu",
    "name",
    "first_name",
    "middle_name",
    "last_name",
    "gender",
    "hl1",
    "hl2",
    "hl3",
    "sl1",
    "sl2",
    "sl3",
    "clearItems",
    "removeCompletedItems",
    "searchStudents",
    "query"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ToDoList[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    1,   64,    2, 0x06,    3 /* Public */,
       6,    0,   67,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,   13,   68,    2, 0x0a,    6 /* Public */,
      21,    0,   95,    2, 0x0a,   20 /* Public */,
      22,    0,   96,    2, 0x0a,   21 /* Public */,
      23,    1,   97,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,

       0        // eod
};

Q_CONSTINIT const QMetaObject ToDoList::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ToDoList.offsetsAndSizes,
    qt_meta_data_ToDoList,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ToDoList_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ToDoList, std::true_type>,
        // method 'preItemAppended'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'postItemAppended'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'preItemRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'postItemRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'appendItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        // method 'clearItems'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeCompletedItems'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchStudents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void ToDoList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToDoList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->preItemRemoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->postItemRemoved(); break;
        case 4: _t->appendItem((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[13]))); break;
        case 5: _t->clearItems(); break;
        case 6: _t->removeCompletedItems(); break;
        case 7: _t->searchStudents((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ToDoList::*)();
            if (_t _q_method = &ToDoList::preItemAppended; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ToDoList::*)();
            if (_t _q_method = &ToDoList::postItemAppended; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ToDoList::*)(int );
            if (_t _q_method = &ToDoList::preItemRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ToDoList::*)();
            if (_t _q_method = &ToDoList::postItemRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *ToDoList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToDoList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToDoList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ToDoList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ToDoList::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ToDoList::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ToDoList::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ToDoList::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
