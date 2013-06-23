#include "cooler_ui.h"
#include "ui_cooler_ui.h"

Cooler_UI::Cooler_UI(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::Cooler_UI)
{
    m_ui->setupUi(this);
}

Cooler_UI::~Cooler_UI()
{
    delete m_ui;
}

void Cooler_UI::changeEvent(QEvent *e)
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

void Cooler_UI::on_powerButton_clicked()
{

}

void Cooler_UI::on_tempUpButton_clicked()
{

}

void Cooler_UI::on_tempDownButton_clicked()
{

}

void Cooler_UI::on_windUpButton_clicked()
{

}

void Cooler_UI::on_windDownButton_clicked()
{

}

void Cooler_UI::setCooler(CE* cooler)
{
    this->cooler = cooler;
}
