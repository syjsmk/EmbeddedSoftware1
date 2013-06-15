/********************************************************************************
** Form generated from reading ui file 'ceselector_ui.ui'
**
** Created: Sat Jun 15 16:47:54 2013
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CESELECTOR_UI_H
#define UI_CESELECTOR_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

class Ui_CESelector_UI
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CESelector_UI)
    {
    if (CESelector_UI->objectName().isEmpty())
        CESelector_UI->setObjectName(QString::fromUtf8("CESelector_UI"));
    CESelector_UI->resize(800, 600);
    menubar = new QMenuBar(CESelector_UI);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    CESelector_UI->setMenuBar(menubar);
    centralwidget = new QWidget(CESelector_UI);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    CESelector_UI->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(CESelector_UI);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    CESelector_UI->setStatusBar(statusbar);

    retranslateUi(CESelector_UI);

    QMetaObject::connectSlotsByName(CESelector_UI);
    } // setupUi

    void retranslateUi(QMainWindow *CESelector_UI)
    {
    CESelector_UI->setWindowTitle(QApplication::translate("CESelector_UI", "MainWindow", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CESelector_UI);
    } // retranslateUi

};

namespace Ui {
    class CESelector_UI: public Ui_CESelector_UI {};
} // namespace Ui

#endif // UI_CESELECTOR_UI_H
