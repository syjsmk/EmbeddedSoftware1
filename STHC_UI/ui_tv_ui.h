/********************************************************************************
** Form generated from reading ui file 'tv_ui.ui'
**
** Created: Sat Jun 15 16:41:29 2013
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TV_UI_H
#define UI_TV_UI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

class Ui_TV_UI
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hboxLayout;
    QGraphicsView *graphicsView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *chLabel;
    QLabel *chValueLabel;
    QLabel *volLabel;
    QLabel *volValueLabel;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout1;
    QLabel *chButtonLabel;
    QPushButton *chUpButton;
    QPushButton *chDownButton;
    QLabel *volButtonLabel;
    QPushButton *volUpButton;
    QPushButton *volDownButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *hboxLayout1;
    QLabel *powerLabel;
    QPushButton *powerButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TV_UI)
    {
    if (TV_UI->objectName().isEmpty())
        TV_UI->setObjectName(QString::fromUtf8("TV_UI"));
    TV_UI->resize(600, 400);
    centralWidget = new QWidget(TV_UI);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    horizontalLayoutWidget = new QWidget(centralWidget);
    horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
    horizontalLayoutWidget->setGeometry(QRect(-1, -1, 441, 341));
    hboxLayout = new QHBoxLayout(horizontalLayoutWidget);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(11);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    hboxLayout->setContentsMargins(0, 0, 0, 0);
    graphicsView = new QGraphicsView(horizontalLayoutWidget);
    graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

    hboxLayout->addWidget(graphicsView);

    gridLayoutWidget = new QWidget(centralWidget);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(440, 0, 161, 161));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    chLabel = new QLabel(gridLayoutWidget);
    chLabel->setObjectName(QString::fromUtf8("chLabel"));
    chLabel->setLayoutDirection(Qt::LeftToRight);
    chLabel->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(chLabel, 0, 0, 1, 1);

    chValueLabel = new QLabel(gridLayoutWidget);
    chValueLabel->setObjectName(QString::fromUtf8("chValueLabel"));

    gridLayout->addWidget(chValueLabel, 0, 1, 1, 1);

    volLabel = new QLabel(gridLayoutWidget);
    volLabel->setObjectName(QString::fromUtf8("volLabel"));
    volLabel->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(volLabel, 1, 0, 1, 1);

    volValueLabel = new QLabel(gridLayoutWidget);
    volValueLabel->setObjectName(QString::fromUtf8("volValueLabel"));

    gridLayout->addWidget(volValueLabel, 1, 1, 1, 1);

    gridLayoutWidget_2 = new QWidget(centralWidget);
    gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
    gridLayoutWidget_2->setGeometry(QRect(440, 230, 161, 111));
    gridLayout1 = new QGridLayout(gridLayoutWidget_2);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(11);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    gridLayout1->setContentsMargins(0, 0, 0, 0);
    chButtonLabel = new QLabel(gridLayoutWidget_2);
    chButtonLabel->setObjectName(QString::fromUtf8("chButtonLabel"));
    chButtonLabel->setMaximumSize(QSize(40, 16777215));

    gridLayout1->addWidget(chButtonLabel, 0, 0, 1, 1);

    chUpButton = new QPushButton(gridLayoutWidget_2);
    chUpButton->setObjectName(QString::fromUtf8("chUpButton"));
    chUpButton->setMaximumSize(QSize(40, 16777215));

    gridLayout1->addWidget(chUpButton, 0, 1, 1, 1);

    chDownButton = new QPushButton(gridLayoutWidget_2);
    chDownButton->setObjectName(QString::fromUtf8("chDownButton"));
    chDownButton->setMaximumSize(QSize(40, 16777215));

    gridLayout1->addWidget(chDownButton, 0, 2, 1, 1);

    volButtonLabel = new QLabel(gridLayoutWidget_2);
    volButtonLabel->setObjectName(QString::fromUtf8("volButtonLabel"));
    volButtonLabel->setMaximumSize(QSize(40, 20));

    gridLayout1->addWidget(volButtonLabel, 1, 0, 1, 1);

    volUpButton = new QPushButton(gridLayoutWidget_2);
    volUpButton->setObjectName(QString::fromUtf8("volUpButton"));
    volUpButton->setMaximumSize(QSize(40, 16777215));

    gridLayout1->addWidget(volUpButton, 1, 1, 1, 1);

    volDownButton = new QPushButton(gridLayoutWidget_2);
    volDownButton->setObjectName(QString::fromUtf8("volDownButton"));
    volDownButton->setMaximumSize(QSize(40, 16777215));

    gridLayout1->addWidget(volDownButton, 1, 2, 1, 1);

    horizontalLayoutWidget_2 = new QWidget(centralWidget);
    horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
    horizontalLayoutWidget_2->setGeometry(QRect(440, 160, 161, 71));
    hboxLayout1 = new QHBoxLayout(horizontalLayoutWidget_2);
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(11);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    hboxLayout1->setContentsMargins(0, 0, 0, 0);
    powerLabel = new QLabel(horizontalLayoutWidget_2);
    powerLabel->setObjectName(QString::fromUtf8("powerLabel"));
    powerLabel->setAlignment(Qt::AlignCenter);

    hboxLayout1->addWidget(powerLabel);

    powerButton = new QPushButton(horizontalLayoutWidget_2);
    powerButton->setObjectName(QString::fromUtf8("powerButton"));

    hboxLayout1->addWidget(powerButton);

    TV_UI->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(TV_UI);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 600, 23));
    TV_UI->setMenuBar(menuBar);
    mainToolBar = new QToolBar(TV_UI);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    TV_UI->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(TV_UI);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    TV_UI->setStatusBar(statusBar);

    retranslateUi(TV_UI);

    QMetaObject::connectSlotsByName(TV_UI);
    } // setupUi

    void retranslateUi(QMainWindow *TV_UI)
    {
    TV_UI->setWindowTitle(QApplication::translate("TV_UI", "TV_UI", 0, QApplication::UnicodeUTF8));
    chLabel->setText(QApplication::translate("TV_UI", "Ch.", 0, QApplication::UnicodeUTF8));
    chValueLabel->setText(QApplication::translate("TV_UI", "TextLabel", 0, QApplication::UnicodeUTF8));
    volLabel->setText(QApplication::translate("TV_UI", "Vol.", 0, QApplication::UnicodeUTF8));
    volValueLabel->setText(QApplication::translate("TV_UI", "TextLabel", 0, QApplication::UnicodeUTF8));
    chButtonLabel->setText(QApplication::translate("TV_UI", "Ch.", 0, QApplication::UnicodeUTF8));
    chUpButton->setText(QApplication::translate("TV_UI", "\342\226\262", 0, QApplication::UnicodeUTF8));
    chDownButton->setText(QApplication::translate("TV_UI", "\342\226\274", 0, QApplication::UnicodeUTF8));
    volButtonLabel->setText(QApplication::translate("TV_UI", "Vol.", 0, QApplication::UnicodeUTF8));
    volUpButton->setText(QApplication::translate("TV_UI", "\342\226\262", 0, QApplication::UnicodeUTF8));
    volDownButton->setText(QApplication::translate("TV_UI", "\342\226\274", 0, QApplication::UnicodeUTF8));
    powerLabel->setText(QApplication::translate("TV_UI", "Power", 0, QApplication::UnicodeUTF8));
    powerButton->setText(QApplication::translate("TV_UI", "PushButton", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(TV_UI);
    } // retranslateUi

};

namespace Ui {
    class TV_UI: public Ui_TV_UI {};
} // namespace Ui

#endif // UI_TV_UI_H
