#include "tv_ui.h"
#include "ui_tv_ui.h"

TV_UI::TV_UI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TV_UI)
{
    ui->setupUi(this);
    //this->netMgr = new IoInterface();
    //netMgr->broadcast();
    qDebug() << "STARTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT";

    this->hmmanager = new HMManager();
    this->hmmanager->listenBroadcast();

}

TV_UI::~TV_UI()
{
    delete ui;

}

void TV_UI::on_powerButton_clicked()
{
    qDebug() << "powerButton clicked";
    hmmanager->sendMessage();
}

void TV_UI::on_chUpButton_clicked()
{
    qDebug() << "on_chUpButton_clicked()";
    QList<CE*> *ceList = hmmanager->getCeList();
    qDebug() << "CE SIZE : " << ceList->size();

    CE* ce;
    QString t;
    foreach(ce, *ceList)
    {

        t.sprintf("CE type : %x, firstAttr %x, secondAttr : %x, thirdAttr : %x", ce->type, ce->firstAttr, ce->secondAttr, ce->thirdAttr);
        qDebug() << t;
    }

}

void TV_UI::on_chDownButton_clicked()
{

}

void TV_UI::on_volUpButton_clicked()
{

}

void TV_UI::on_volDownButton_clicked()
{

}
