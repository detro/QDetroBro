/****************************************************************************
** Meta object code from reading C++ file 'QDetroBro.h'
**
** Created: Fri 24. Jul 16:47:48 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2-tower)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QDetroBro.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDetroBro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2-tower. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDetroBro[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      24,   10,   10,   10, 0x08,
      38,   10,   10,   10, 0x08,
      62,   55,   10,   10, 0x08,
      95,   90,   10,   10, 0x08,
     155,  123,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QDetroBro[] = {
    "QDetroBro\0\0initialize()\0loadHomeUrl()\0"
    "loadCurrentUrl()\0aValue\0"
    "updateWebViewZoomLevel(int)\0aUrl\0"
    "updateAddressLineEdit(QUrl)\0"
    "aOldFocusWidget,aNowFocusWidget\0"
    "handleFocusChange(QWidget*,QWidget*)\0"
};

const QMetaObject QDetroBro::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QDetroBro,
      qt_meta_data_QDetroBro, 0 }
};

const QMetaObject *QDetroBro::metaObject() const
{
    return &staticMetaObject;
}

void *QDetroBro::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDetroBro))
        return static_cast<void*>(const_cast< QDetroBro*>(this));
    return QWidget::qt_metacast(_clname);
}

int QDetroBro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initialize(); break;
        case 1: loadHomeUrl(); break;
        case 2: loadCurrentUrl(); break;
        case 3: updateWebViewZoomLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: updateAddressLineEdit((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 5: handleFocusChange((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
