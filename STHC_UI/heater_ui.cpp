#include "heater_ui.h"
#include "ui_heater_ui.h"

Heater_UI::Heater_UI(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::Heater_UI)
{
    m_ui->setupUi(this);

    qDebug() << "dddddddasdasdasdas";


}

Heater_UI::~Heater_UI()
{
    delete m_ui;
}

void Heater_UI::changeEvent(QEvent *e)
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

void Heater_UI::on_powerButton_clicked()
{
    qDebug() << "FUCkINGGGGGGGGGGGGGGGGGGGGGGGGGG HEAAAAAATTTTTTTEEEEEEEERRRRRRRR";
    QString t;
    t.sprintf("CE type : %x, firstAttr %x, secondAttr : %x, thirdAttr : %x", heater->type, heater->firstAttr, heater->secondAttr, heater->thirdAttr);
    qDebug() << t;

    QString temp;
    temp.sprintf("%d", heater->firstAttr);
    m_ui->powerLabel->setText(temp);
    temp.sprintf("%d", heater->secondAttr);
    m_ui->temperatureVauleLabel->setText(temp);
    temp.sprintf("%d", heater->thirdAttr);
    m_ui->windValueLabel->setText(temp);
}

void Heater_UI::on_windUpButton_clicked()
{

}

void Heater_UI::on_windDownButton_clicked()
{

}

void Heater_UI::on_tempUpButton_clicked()
{

}

void Heater_UI::on_tempDownButton_clicked()
{

}
void Heater_UI::setHeater(CE* heater)
{
    this->heater = heater;
}
