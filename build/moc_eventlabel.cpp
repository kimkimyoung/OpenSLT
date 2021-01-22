/****************************************************************************
** Meta object code from reading C++ file 'eventlabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eventlabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventlabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventLabel_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventLabel_t qt_meta_stringdata_EventLabel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EventLabel"
QT_MOC_LITERAL(1, 11, 18), // "mouseReleaseSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "rectLocationSet"
QT_MOC_LITERAL(4, 47, 10), // "QList<int>"
QT_MOC_LITERAL(5, 58, 14), // "deleteRectlist"
QT_MOC_LITERAL(6, 73, 14) // "deleteLastRect"

    },
    "EventLabel\0mouseReleaseSignal\0\0"
    "rectLocationSet\0QList<int>\0deleteRectlist\0"
    "deleteLastRect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EventLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EventLabel *_t = static_cast<EventLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseReleaseSignal(); break;
        case 1: _t->rectLocationSet((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 2: _t->deleteRectlist(); break;
        case 3: _t->deleteLastRect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EventLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EventLabel::mouseReleaseSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EventLabel::*_t)(QList<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EventLabel::rectLocationSet)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject EventLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_EventLabel.data,
      qt_meta_data_EventLabel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EventLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventLabel.stringdata0))
        return static_cast<void*>(const_cast< EventLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int EventLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void EventLabel::mouseReleaseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EventLabel::rectLocationSet(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
