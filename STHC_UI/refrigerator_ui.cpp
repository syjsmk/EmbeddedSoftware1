#include "refrigerator_ui.h"
#include "ui_refrigerator_ui.h"

Refrigerator_UI::Refrigerator_UI(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::Refrigerator_UI)
{
    m_ui->setupUi(this);
}

Refrigerator_UI::~Refrigerator_UI()
{
    delete m_ui;
}

void Refrigerator_UI::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Refrigerator_UI::on_powerButton_clicked()
{

}

void Refrigerator_UI::on_tempUpButton_clicked()
{

}

void Refrigerator_UI::on_tempDownButton_clicked()
{

}
