/****************************************************************************
** Meta object code from reading C++ file 'hmmanager.h'
**
** Created: Thu Jun 13 13:45:44 2013
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hmmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hmmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_HMManager[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_HMManager[] = {
    "HMManager\0"
};

const QMetaObject HMManager::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HMManager,
      qt_meta_data_HMManager, 0 }
};

const QMetaObject *HMManager::metaObject() const
{
    return &staticMetaObject;
}

void *HMManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HMManager))
	return static_cast<void*>(const_cast< HMManager*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HMManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
