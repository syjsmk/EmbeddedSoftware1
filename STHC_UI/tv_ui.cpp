#include "tv_ui.h"
#include "ui_tv_ui.h"

TV_UI::TV_UI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TV_UI)
{
    ui->setupUi(this);
    //this->netMgr = new IoInterface();
    //netMgr->broadcast();
    qDebug() << "STARTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT";


}

TV_UI::~TV_UI()
{
    delete ui;
}

void TV_UI::on_powerButton_clicked()
{
    qDebug() << "powerButton clicked";

    //ioInterface->sendMessage(
    QString t;
    t.sprintf("CE type : %x, firstAttr %x, secondAttr : %x, thirdAttr : %x", tv->type, tv->firstAttr, tv->secondAttr, tv->thirdAttr);
    qDebug() << t;

}

void TV_UI::on_chUpButton_clicked()
{
    int data = 1;
    QString temp;
    if(tv->secondAttr + 0x01 > MAXCH)
    {
         tv->secondAttr = MINCH;
    }
     else
         tv->secondAttr += 0x01;

    ret = ioctl(tv->dev, signal_ioctl3, &data);
    temp.sprintf("%d", tv->secondAttr);
    ui->chValueLabel->setText(temp);
}

void TV_UI::on_chDownButton_clicked()
{
    int data = 2;
    QString temp;
    if(tv->secondAttr - 0x01 < MINCH)
    {
        tv->secondAttr = MAXCH;
    }
    else
        tv->secondAttr -= 0x01;

    ret = ioctl(tv->dev, signal_ioctl3, &data);
    temp.sprintf("%d", tv->secondAttr);
    ui->chValueLabel->setText(temp);
}

void TV_UI::on_volUpButton_clicked()
{
    int data = 3;
    QString temp;
    if(tv->thirdAttr + 0x01 > MAXVOL)
    {
        tv->thirdAttr = MAXVOL;
    }
    else
        tv->thirdAttr += 0x01;

    ret = ioctl(tv->dev, signal_ioctl3, &data);
    temp.sprintf("%d", tv->thirdAttr);
    ui->volValueLabel->setText(temp);
}

void TV_UI::on_volDownButton_clicked()
{
    int data = 4;
    QString temp;
    if(tv->thirdAttr - 0x01 < MINCH)
    {
        tv->thirdAttr = MINVOL;
    }
    else
        tv->thirdAttr -= 0x01;

    ret = ioctl(tv->dev, signal_ioctl3, &data);
    temp.sprintf("%d", tv->thirdAttr);
    ui->volValueLabel->setText(temp);
}

void TV_UI::setTv(CE *tv)
{
    qDebug() << "setTv";
    this->tv = tv;
}

void TV_UI::initData()
{
    QString temp;
    if(tv->firstAttr == 0x01)
    {
        temp.sprintf("off");
    } else {
        temp.sprintf("on");
    }

    ui->powerButton->setText(temp);
    temp.sprintf("%d", tv->secondAttr);
    ui->chValueLabel->setText(temp);
    temp.sprintf("%d", tv->thirdAttr);
    ui->volValueLabel->setText(temp);
}
