/****************************************************************************
** Meta object code from reading C++ file 'settingbeginning.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../0706-2/settingbeginning.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingbeginning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_settingBeginning_t {
    QByteArrayData data[9];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_settingBeginning_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_settingBeginning_t qt_meta_stringdata_settingBeginning = {
    {
QT_MOC_LITERAL(0, 0, 16), // "settingBeginning"
QT_MOC_LITERAL(1, 17, 9), // "volumn_on"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "volumn_off"
QT_MOC_LITERAL(4, 39, 8), // "music_on"
QT_MOC_LITERAL(5, 48, 9), // "music_off"
QT_MOC_LITERAL(6, 58, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(7, 78, 17), // "on_volume_clicked"
QT_MOC_LITERAL(8, 96, 16) // "on_music_clicked"

    },
    "settingBeginning\0volumn_on\0\0volumn_off\0"
    "music_on\0music_off\0on_okButton_clicked\0"
    "on_volume_clicked\0on_music_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_settingBeginning[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void settingBeginning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<settingBeginning *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->volumn_on(); break;
        case 1: _t->volumn_off(); break;
        case 2: _t->music_on(); break;
        case 3: _t->music_off(); break;
        case 4: _t->on_okButton_clicked(); break;
        case 5: _t->on_volume_clicked(); break;
        case 6: _t->on_music_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (settingBeginning::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingBeginning::volumn_on)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (settingBeginning::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingBeginning::volumn_off)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (settingBeginning::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingBeginning::music_on)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (settingBeginning::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settingBeginning::music_off)) {
                *result = 3;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject settingBeginning::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_settingBeginning.data,
    qt_meta_data_settingBeginning,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *settingBeginning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *settingBeginning::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_settingBeginning.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int settingBeginning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void settingBeginning::volumn_on()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void settingBeginning::volumn_off()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void settingBeginning::music_on()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void settingBeginning::music_off()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
