/********************************************************************************
** Form generated from reading ui file 'ceselector_ui.ui'
**
** Created: Sat Jun 15 16:14:51 2013
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
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

class Ui_CESelector_UI
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout1;
    QLabel *chLabel;
    QLabel *chValueLabel;
    QLabel *volLabel;
    QLabel *volValueLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CESelector_UI)
    {
    if (CESelector_UI->objectName().isEmpty())
        CESelector_UI->setObjectName(QString::fromUtf8("CESelector_UI"));
    CESelector_UI->resize(600, 400);
    CESelector_UI->setMaximumSize(QSize(600, 400));
    centralwidget = new QWidget(CESelector_UI);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayoutWidget = new QWidget(centralwidget);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(-1, -1, 471, 351));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayoutWidget_2 = new QWidget(centralwidget);
    gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
    gridLayoutWidget_2->setGeometry(QRect(470, 0, 131, 351));
    gridLayout1 = new QGridLayout(gridLayoutWidget_2);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    gridLayout1->setContentsMargins(0, 0, 0, 0);
    chLabel = new QLabel(gridLayoutWidget_2);
    chLabel->setObjectName(QString::fromUtf8("chLabel"));
    chLabel->setAlignment(Qt::AlignCenter);

    gridLayout1->addWidget(chLabel, 0, 0, 1, 1);

    chValueLabel = new QLabel(gridLayoutWidget_2);
    chValueLabel->setObjectName(QString::fromUtf8("chValueLabel"));

    gridLayout1->addWidget(chValueLabel, 0, 1, 1, 1);

    volLabel = new QLabel(gridLayoutWidget_2);
    volLabel->setObjectName(QString::fromUtf8("volLabel"));
    volLabel->setAlignment(Qt::AlignCenter);

    gridLayout1->addWidget(volLabel, 1, 0, 1, 1);

    volValueLabel = new QLabel(gridLayoutWidget_2);
    volValueLabel->setObjectName(QString::fromUtf8("volValueLabel"));

    gridLayout1->addWidget(volValueLabel, 1, 1, 1, 1);

    CESelector_UI->setCentralWidget(centralwidget);
    menubar = new QMenuBar(CESelector_UI);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 600, 23));
    CESelector_UI->setMenuBar(menubar);
    statusbar = new QStatusBar(CESelector_UI);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    CESelector_UI->setStatusBar(statusbar);

    retranslateUi(CESelector_UI);

    QMetaObject::connectSlotsByName(CESelector_UI);
    } // setupUi

    void retranslateUi(QMainWindow *CESelector_UI)
    {
    CESelector_UI->setWindowTitle(QApplication::translate("CESelector_UI", "MainWindow", 0, QApplication::UnicodeUTF8));
    chLabel->setText(QApplication::translate("CESelector_UI", "Ch.", 0, QApplication::UnicodeUTF8));
    chValueLabel->setText(QApplication::translate("CESelector_UI", "TextLabel", 0, QApplication::UnicodeUTF8));
    volLabel->setText(QApplication::translate("CESelector_UI", "Vol.", 0, QApplication::UnicodeUTF8));
    volValueLabel->setText(QApplication::translate("CESelector_UI", "TextLabel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CESelector_UI);
    } // retranslateUi

};

namespace Ui {
    class CESelector_UI: public Ui_CESelector_UI {};
} // namespace Ui

#endif // UI_CESELECTOR_UI_H
