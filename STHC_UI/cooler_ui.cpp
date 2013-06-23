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
    if(cooler->firstAttr == 0x01)
    {
        cooler->firstAttr = 0x00;
    } else {
        cooler->firstAttr = 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_SET, ATTRIBUTE_FIRST, cooler->firstAttr);
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);

    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_GET, ATTRIBUTE_FIRST, cooler->firstAttr);
    initData();
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);
}

void Cooler_UI::on_tempUpButton_clicked()
{
    if((cooler->secondAttr + 0x01) < 35)
    {
        cooler->secondAttr += 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_SET, ATTRIBUTE_SECOND, cooler->secondAttr);
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);

    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, cooler->secondAttr);
    initData();
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);
}

void Cooler_UI::on_tempDownButton_clicked()
{
    if((cooler->secondAttr - 0x01) > 15)
    {
        cooler->secondAttr = cooler->secondAttr -  0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_SET, ATTRIBUTE_SECOND, cooler->secondAttr);
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);

    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, cooler->secondAttr);

    initData();
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);
}

void Cooler_UI::on_windUpButton_clicked()
{
    if((cooler->thirdAttr + 0x01) < 101)
    {
        cooler->thirdAttr += 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_SET, ATTRIBUTE_THIRD, cooler->thirdAttr);
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);

    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_GET, ATTRIBUTE_THIRD, cooler->thirdAttr);
    initData();
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);
}

void Cooler_UI::on_windDownButton_clicked()
{
    if((cooler->thirdAttr - 0x01) > 0)
    {
        cooler->thirdAttr -= 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_SET, ATTRIBUTE_THIRD, cooler->thirdAttr);
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);

    message = ioInterface->makeMessage(cooler->type, MESSAGE_OPTION_GET, ATTRIBUTE_THIRD, cooler->thirdAttr);
    initData();
    ioInterface->sendMessage(cooler->socket, message, cooler->addr, 1106);
}

void Cooler_UI::setCooler(CE* cooler)
{
    this->cooler = cooler;
}

void Cooler_UI::initData()
{
    QString temp;
    if(cooler->firstAttr == 0x01)
    {
        temp.sprintf("off");
    } else {
        temp.sprintf("on");
    }

    m_ui->powerButton->setText(temp);
    temp.sprintf("%d", cooler->secondAttr);
    m_ui->temperatureVauleLabel->setText(temp);
    temp.sprintf("%d", cooler->thirdAttr);
    m_ui->windValueLabel->setText(temp);
}
