/********************************************************************************
** Form generated from reading ui file 'CESelectUi.ui'
**
** Created: Thu Jun 13 15:34:16 2013
**      by: Qt User Interface Compiler version 4.3.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CESELECTUI_H
#define UI_CESELECTUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

class Ui_Form
{
public:

    void setupUi(QWidget *Form)
    {
    if (Form->objectName().isEmpty())
        Form->setObjectName(QString::fromUtf8("Form"));
    Form->resize(600, 400);

    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
    Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Form);
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

#endif // UI_CESELECTUI_H
