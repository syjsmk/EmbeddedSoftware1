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

void Heater_UI::initData()
{
    QString temp;
    if(heater->firstAttr == 0x01)
    {
        temp.sprintf("off");
    } else {
        temp.sprintf("on");
    }

    m_ui->powerButton->setText(temp);
    temp.sprintf("%d", heater->secondAttr);
    m_ui->temperatureVauleLabel->setText(temp);
    temp.sprintf("%d", heater->thirdAttr);
    m_ui->windValueLabel->setText(temp);
}
