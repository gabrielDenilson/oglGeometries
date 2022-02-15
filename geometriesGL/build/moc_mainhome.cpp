/****************************************************************************
** Meta object code from reading C++ file 'mainhome.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/VentanaPrincipal/mainhome.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainhome.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainHome_t {
    QByteArrayData data[13];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainHome_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainHome_t qt_meta_stringdata_MainHome = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainHome"
QT_MOC_LITERAL(1, 9, 14), // "slotMenuToggle"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "slotLeftBoxToggle"
QT_MOC_LITERAL(4, 43, 18), // "slotRightBoxToggle"
QT_MOC_LITERAL(5, 62, 14), // "setCurrentHome"
QT_MOC_LITERAL(6, 77, 15), // "setCurrentHome2"
QT_MOC_LITERAL(7, 93, 15), // "setCurrentHome3"
QT_MOC_LITERAL(8, 109, 15), // "setCurrentHome4"
QT_MOC_LITERAL(9, 125, 17), // "showFormAddClient"
QT_MOC_LITERAL(10, 143, 8), // "makePush"
QT_MOC_LITERAL(11, 152, 13), // "closedDrawing"
QT_MOC_LITERAL(12, 166, 33) // "on_pushButtonStartDrawing_cli..."

    },
    "MainHome\0slotMenuToggle\0\0slotLeftBoxToggle\0"
    "slotRightBoxToggle\0setCurrentHome\0"
    "setCurrentHome2\0setCurrentHome3\0"
    "setCurrentHome4\0showFormAddClient\0"
    "makePush\0closedDrawing\0"
    "on_pushButtonStartDrawing_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainHome[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x08 /* Private */,

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

       0        // eod
};

void MainHome::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainHome *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotMenuToggle(); break;
        case 1: _t->slotLeftBoxToggle(); break;
        case 2: _t->slotRightBoxToggle(); break;
        case 3: _t->setCurrentHome(); break;
        case 4: _t->setCurrentHome2(); break;
        case 5: _t->setCurrentHome3(); break;
        case 6: _t->setCurrentHome4(); break;
        case 7: _t->showFormAddClient(); break;
        case 8: _t->makePush(); break;
        case 9: _t->closedDrawing(); break;
        case 10: _t->on_pushButtonStartDrawing_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MainHome::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainHome.data,
    qt_meta_data_MainHome,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainHome::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainHome::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainHome.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainHome::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
