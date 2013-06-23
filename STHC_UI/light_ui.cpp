#include "light_ui.h"
#include "ui_light_ui.h"

Light_UI::Light_UI(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::Light_UI)
{
    m_ui->setupUi(this);

    ioInterface = new IoInterface();
}

Light_UI::~Light_UI()
{
    delete m_ui;
    delete ioInterface;
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
    if(light->firstAttr == 0x01)
    {
        light->firstAttr = 0x00;
    } else {
        light->firstAttr = 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(light->type, MESSAGE_OPTION_SET, ATTRIBUTE_FIRST, light->firstAttr);
    ioInterface->sendMessage(light->socket, message, light->addr, 1106);

    message = ioInterface->makeMessage(light->type, MESSAGE_OPTION_GET, ATTRIBUTE_FIRST, light->firstAttr);
    initData();
    ioInterface->sendMessage(light->socket, message, light->addr, 1106);
}

void Light_UI::on_brightUpButton_clicked()
{
    if((light->secondAttr + 0x01) < 101)
    {
        light->secondAttr += 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(light->type, MESSAGE_OPTION_SET, ATTRIBUTE_SECOND, light->secondAttr);
    ioInterface->sendMessage(light->socket, message, light->addr, 1106);

    message = ioInterface->makeMessage(light->type, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, light->secondAttr);
    initData();
    ioInterface->sendMessage(light->socket, message, light->addr, 1106);
}

void Light_UI::on_brightDownButton_clicked()
{
    if((light->secondAttr - 0x01) > 0)
    {
        light->secondAttr -= 0x01;
    }

    QByteArray message;
    message = ioInterface->makeMessage(light->type, MESSAGE_OPTION_SET, ATTRIBUTE_SECOND, light->secondAttr);
    ioInterface->sendMessage(light->socket, message, light->addr, 1106);

    message = ioInterface->makeMessage(light->type, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, light->secondAttr);

    initData();
    ioInterface->sendMessage(light->socket, message, light->addr, 1106);
}

void Light_UI::setLight(CE *light)
{
    this->light = light;
}

void Light_UI::initData()
{
    QString temp;
    if(light->firstAttr == 0x01)
    {
        temp.sprintf("off");
    } else {
        temp.sprintf("on");
    }

    m_ui->powerButton->setText(temp);
    temp.sprintf("%d", light->secondAttr);
    m_ui->brightnessVauleLabel->setText(temp);
    m_ui->ipLabel->setText(light->addr.toString());
}
