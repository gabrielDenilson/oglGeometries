/****************************************************************************
** Meta object code from reading C++ file 'formdrawable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../formdrawable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formdrawable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormDrawable_t {
    QByteArrayData data[9];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormDrawable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormDrawable_t qt_meta_stringdata_FormDrawable = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FormDrawable"
QT_MOC_LITERAL(1, 13, 10), // "draw_order"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "draw"
QT_MOC_LITERAL(4, 30, 4), // "TIPO"
QT_MOC_LITERAL(5, 35, 24), // "buttonLinea_click_action"
QT_MOC_LITERAL(6, 60, 29), // "buttonLineaPadre_click_action"
QT_MOC_LITERAL(7, 90, 28), // "buttonLineaHija_click_action"
QT_MOC_LITERAL(8, 119, 24) // "buttonPunto_click_action"

    },
    "FormDrawable\0draw_order\0\0draw\0TIPO\0"
    "buttonLinea_click_action\0"
    "buttonLineaPadre_click_action\0"
    "buttonLineaHija_click_action\0"
    "buttonPunto_click_action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormDrawable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormDrawable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormDrawable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->draw_order((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< TIPO(*)>(_a[2]))); break;
        case 1: _t->buttonLinea_click_action(); break;
        case 2: _t->buttonLineaPadre_click_action(); break;
        case 3: _t->buttonLineaHija_click_action(); break;
        case 4: _t->buttonPunto_click_action(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormDrawable::*)(bool , TIPO );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormDrawable::draw_order)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormDrawable::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormDrawable.data,
    qt_meta_data_FormDrawable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormDrawable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormDrawable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormDrawable.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormDrawable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FormDrawable::draw_order(bool _t1, TIPO _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
