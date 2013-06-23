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
    if(refrigerator->firstAttr == 0x01)
    {
        refrigerator->firstAttr = 0x00;
    } else {
        refrigerator->firstAttr = 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(refrigerator->type, MESSAGE_OPTION_SET, ATTRIBUTE_FIRST, refrigerator->firstAttr);
    ioInterface->sendMessage(refrigerator->socket, message, refrigerator->addr, 1106);

    message = ioInterface->makeMessage(refrigerator->type, MESSAGE_OPTION_GET, ATTRIBUTE_FIRST, refrigerator->firstAttr);
    initData();
    ioInterface->sendMessage(refrigerator->socket, message, refrigerator->addr, 1106);
}

void Refrigerator_UI::on_tempUpButton_clicked()
{
    if((refrigerator->secondAttr + 0x01) < 16)
    {
        refrigerator->secondAttr += 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(refrigerator->type, MESSAGE_OPTION_SET, ATTRIBUTE_SECOND, refrigerator->secondAttr);
    ioInterface->sendMessage(refrigerator->socket, message, refrigerator->addr, 1106);

    message = ioInterface->makeMessage(refrigerator->type, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, refrigerator->secondAttr);
    initData();
    ioInterface->sendMessage(refrigerator->socket, message, refrigerator->addr, 1106);
}

void Refrigerator_UI::on_tempDownButton_clicked()
{
    if((refrigerator->secondAttr - 0x01) > -14)
    {
        refrigerator->secondAttr -= 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(refrigerator->type, MESSAGE_OPTION_SET, ATTRIBUTE_SECOND, refrigerator->secondAttr);
    ioInterface->sendMessage(refrigerator->socket, message, refrigerator->addr, 1106);

    message = ioInterface->makeMessage(refrigerator->type, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, refrigerator->secondAttr);

    initData();
    ioInterface->sendMessage(refrigerator->socket, message, refrigerator->addr, 1106);
}
void Refrigerator_UI::setRefeigerator(CE *refrigerator)
{
    this->refrigerator = refrigerator;
}

void Refrigerator_UI::initData()
{
     QString temp;
    if(refrigerator->firstAttr == 0x01)
    {
        temp.sprintf("off");
    } else {
        temp.sprintf("on");
    }

    m_ui->powerButton->setText(temp);
    temp.sprintf("%d", refrigerator->secondAttr);
    m_ui->temperatureVauleLabel->setText(temp);
}
