#include "light_ui.h"
#include "ui_light_ui.h"

Light_UI::Light_UI(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::Light_UI)
{
    m_ui->setupUi(this);
}

Light_UI::~Light_UI()
{
    delete m_ui;
}

void Light_UI::changeEvent(QEvent *e)
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

void Light_UI::on_powerButton_clicked()
{

}

void Light_UI::on_brightUpButton_clicked()
{

}

void Light_UI::on_brightDownButton_clicked()
{

}
