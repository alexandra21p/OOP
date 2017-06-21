/****************************************************************************
** Meta object code from reading C++ file 'myclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyClass_t {
    QByteArrayData data[16];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyClass_t qt_meta_stringdata_MyClass = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyClass"
QT_MOC_LITERAL(1, 8, 15), // "listItemChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "addTutToRepo"
QT_MOC_LITERAL(4, 38, 17), // "deleteTutFromRepo"
QT_MOC_LITERAL(5, 56, 17), // "updateTutFromRepo"
QT_MOC_LITERAL(6, 74, 14), // "filterRepoTuts"
QT_MOC_LITERAL(7, 89, 15), // "playTutFromRepo"
QT_MOC_LITERAL(8, 105, 15), // "nextTutFromRepo"
QT_MOC_LITERAL(9, 121, 17), // "addTutToWatchList"
QT_MOC_LITERAL(10, 139, 19), // "deleteFromWatchList"
QT_MOC_LITERAL(11, 159, 13), // "playWatchList"
QT_MOC_LITERAL(12, 173, 13), // "nextWatchList"
QT_MOC_LITERAL(13, 187, 10), // "saveToFile"
QT_MOC_LITERAL(14, 198, 15), // "openWithProgram"
QT_MOC_LITERAL(15, 214, 14) // "clearLineEdits"

    },
    "MyClass\0listItemChanged\0\0addTutToRepo\0"
    "deleteTutFromRepo\0updateTutFromRepo\0"
    "filterRepoTuts\0playTutFromRepo\0"
    "nextTutFromRepo\0addTutToWatchList\0"
    "deleteFromWatchList\0playWatchList\0"
    "nextWatchList\0saveToFile\0openWithProgram\0"
    "clearLineEdits"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyClass *_t = static_cast<MyClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listItemChanged(); break;
        case 1: _t->addTutToRepo(); break;
        case 2: _t->deleteTutFromRepo(); break;
        case 3: _t->updateTutFromRepo(); break;
        case 4: _t->filterRepoTuts(); break;
        case 5: _t->playTutFromRepo(); break;
        case 6: _t->nextTutFromRepo(); break;
        case 7: _t->addTutToWatchList(); break;
        case 8: _t->deleteFromWatchList(); break;
        case 9: _t->playWatchList(); break;
        case 10: _t->nextWatchList(); break;
        case 11: _t->saveToFile(); break;
        case 12: _t->openWithProgram(); break;
        case 13: _t->clearLineEdits(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyClass::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyClass.data,
      qt_meta_data_MyClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyClass.stringdata0))
        return static_cast<void*>(const_cast< MyClass*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
