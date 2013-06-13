/********************************************************************************
** Form generated from reading ui file 'hmmanager.ui'
**
** Created: Thu Jun 13 13:45:42 2013
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HMMANAGER_H
#define UI_HMMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

class Ui_HMManager
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HMManager)
    {
    if (HMManager->objectName().isEmpty())
        HMManager->setObjectName(QString::fromUtf8("HMManager"));
    HMManager->resize(600, 400);
    menuBar = new QMenuBar(HMManager);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    HMManager->setMenuBar(menuBar);
    mainToolBar = new QToolBar(HMManager);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    HMManager->addToolBar(mainToolBar);
    centralWidget = new QWidget(HMManager);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    HMManager->setCentralWidget(centralWidget);
    statusBar = new QStatusBar(HMManager);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    HMManager->setStatusBar(statusBar);

    retranslateUi(HMManager);

    QMetaObject::connectSlotsByName(HMManager);
    } // setupUi

    void retranslateUi(QMainWindow *HMManager)
    {
    HMManager->setWindowTitle(QApplication::translate("HMManager", "HMManager", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(HMManager);
    } // retranslateUi

};

namespace Ui {
    class HMManager: public Ui_HMManager {};
} // namespace Ui

#endif // UI_HMMANAGER_H
