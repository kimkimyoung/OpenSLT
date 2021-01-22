/****************************************************************************
** Meta object code from reading C++ file 'labeldialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../labeldialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'labeldialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LabelDialog_t {
    QByteArrayData data[16];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LabelDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LabelDialog_t qt_meta_stringdata_LabelDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LabelDialog"
QT_MOC_LITERAL(1, 12, 16), // "dialoglabelAdded"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "label"
QT_MOC_LITERAL(4, 36, 19), // "dialoglabelCanceled"
QT_MOC_LITERAL(5, 56, 10), // "dialogShow"
QT_MOC_LITERAL(6, 67, 8), // "getLabel"
QT_MOC_LITERAL(7, 76, 19), // "getLabelFromManager"
QT_MOC_LITERAL(8, 96, 22), // "deleteLabelFromManager"
QT_MOC_LITERAL(9, 119, 21), // "clearLabelFromManager"
QT_MOC_LITERAL(10, 141, 11), // "labelAccept"
QT_MOC_LITERAL(11, 153, 11), // "labelReject"
QT_MOC_LITERAL(12, 165, 16), // "doubleClickLabel"
QT_MOC_LITERAL(13, 182, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 199, 4), // "item"
QT_MOC_LITERAL(15, 204, 15) // "sigleClickLabel"

    },
    "LabelDialog\0dialoglabelAdded\0\0label\0"
    "dialoglabelCanceled\0dialogShow\0getLabel\0"
    "getLabelFromManager\0deleteLabelFromManager\0"
    "clearLabelFromManager\0labelAccept\0"
    "labelReject\0doubleClickLabel\0"
    "QListWidgetItem*\0item\0sigleClickLabel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabelDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   73,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
       8,    1,   80,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      15,    1,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void LabelDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LabelDialog *_t = static_cast<LabelDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dialoglabelAdded((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->dialoglabelCanceled(); break;
        case 2: _t->dialogShow(); break;
        case 3: _t->getLabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->getLabelFromManager((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->deleteLabelFromManager((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->clearLabelFromManager(); break;
        case 7: _t->labelAccept(); break;
        case 8: _t->labelReject(); break;
        case 9: _t->doubleClickLabel((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->sigleClickLabel((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LabelDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LabelDialog::dialoglabelAdded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LabelDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LabelDialog::dialoglabelCanceled)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LabelDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LabelDialog.data,
      qt_meta_data_LabelDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LabelDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabelDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LabelDialog.stringdata0))
        return static_cast<void*>(const_cast< LabelDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LabelDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LabelDialog::dialoglabelAdded(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LabelDialog::dialoglabelCanceled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
