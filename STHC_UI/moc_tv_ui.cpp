/****************************************************************************
** Meta object code from reading C++ file 'tv_ui.h'
**
** Created: Thu Jun 13 14:34:02 2013
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tv_ui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tv_ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_TV_UI[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_TV_UI[] = {
    "TV_UI\0"
};

const QMetaObject TV_UI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TV_UI,
      qt_meta_data_TV_UI, 0 }
};

const QMetaObject *TV_UI::metaObject() const
{
    return &staticMetaObject;
}

void *TV_UI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TV_UI))
	return static_cast<void*>(const_cast< TV_UI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TV_UI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
