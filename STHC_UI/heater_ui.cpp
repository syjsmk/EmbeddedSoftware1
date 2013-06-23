#include "heater_ui.h"
#include "ui_heater_ui.h"

Heater_UI::Heater_UI(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::Heater_UI)
{
    m_ui->setupUi(this);
    ioInterface = new IoInterface();

    qDebug() << "dddddddasdasdasdas";


}

Heater_UI::~Heater_UI()
{
    delete m_ui;
    delete ioInterface;
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
    if(heater->firstAttr == 0x01)
    {
        heater->firstAttr = 0x00;
    } else {
        heater->firstAttr = 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_SET, ATTRIBUTE_FIRST, heater->firstAttr);
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);

    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_GET, ATTRIBUTE_FIRST, heater->firstAttr);
    initData();
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);
}

void Heater_UI::on_windUpButton_clicked()
{
    if((heater->thirdAttr + 0x01) < 101)
    {
        heater->thirdAttr += 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_SET, ATTRIBUTE_THIRD, heater->thirdAttr);
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);

    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_GET, ATTRIBUTE_THIRD, heater->thirdAttr);
    initData();
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);
}

void Heater_UI::on_windDownButton_clicked()
{
    if((heater->thirdAttr - 0x01) > 0)
    {
        heater->thirdAttr -= 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_SET, ATTRIBUTE_THIRD, heater->thirdAttr);
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);

    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_GET, ATTRIBUTE_THIRD, heater->thirdAttr);
    initData();
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);
}

void Heater_UI::on_tempUpButton_clicked()
{

    if((heater->secondAttr + 0x01) < 35)
    {
        heater->secondAttr += 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_SET, ATTRIBUTE_SECOND, heater->secondAttr);
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);

    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, heater->secondAttr);
    initData();
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);

}

void Heater_UI::on_tempDownButton_clicked()
{

    if((heater->secondAttr - 0x01) > 15)
    {
        heater->secondAttr = heater->secondAttr -  0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_SET, ATTRIBUTE_SECOND, heater->secondAttr);
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);

    message = ioInterface->makeMessage(heater->type, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, heater->secondAttr);

    initData();
    ioInterface->sendMessage(heater->socket, message, heater->addr, 1106);
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
