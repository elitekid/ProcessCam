/****************************************************************************
** Meta object code from reading C++ file 'settingmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../settingmanager.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSettingManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSettingManagerENDCLASS = QtMocHelpers::stringData(
    "SettingManager",
    "setFontColor",
    "",
    "color",
    "getFontColor",
    "setColorCode",
    "colorCode",
    "getColorCode"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSettingManagerENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[15];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[10];
    char stringdata7[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSettingManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSettingManagerENDCLASS_t qt_meta_stringdata_CLASSSettingManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "SettingManager"
        QT_MOC_LITERAL(15, 12),  // "setFontColor"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 5),  // "color"
        QT_MOC_LITERAL(35, 12),  // "getFontColor"
        QT_MOC_LITERAL(48, 12),  // "setColorCode"
        QT_MOC_LITERAL(61, 9),  // "colorCode"
        QT_MOC_LITERAL(71, 12)   // "getColorCode"
    },
    "SettingManager",
    "setFontColor",
    "",
    "color",
    "getFontColor",
    "setColorCode",
    "colorCode",
    "getColorCode"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSettingManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x02,    1 /* Public */,
       4,    0,   41,    2, 0x02,    3 /* Public */,
       5,    1,   42,    2, 0x02,    4 /* Public */,
       7,    0,   45,    2, 0x02,    6 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::QString,

       0        // eod
};

Q_CONSTINIT const QMetaObject SettingManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSettingManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSettingManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSettingManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SettingManager, std::true_type>,
        // method 'setFontColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getFontColor'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setColorCode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getColorCode'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void SettingManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setFontColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: { QString _r = _t->getFontColor();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setColorCode((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { QString _r = _t->getColorCode();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *SettingManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSettingManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SettingManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
