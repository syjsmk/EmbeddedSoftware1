#include "ceselector_ui.h"
#include "ui_ceselector_ui.h"

CESelector_UI::CESelector_UI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CESelector_UI)
{
    ui->setupUi(this);

    coolerList = new QList<CE*>();
    heaterList = new QList<CE*>();
    lightList = new QList<CE*>();
    refrigeratorList = new QList<CE*>();
}

CESelector_UI::~CESelector_UI()
{
    delete ui;
}

void CESelector_UI::setUiList(QList<CE*> *list)
{
    this->ceList = list;
}

void CESelector_UI::selectorUI(int uinum)
{
     CE* ce;
     qDebug() << "djdkaljsfdklajskdlfjiqweirnjz;cvxnkq;nweirojkdljiaos;djfilq;wjelr;jaksld;fnv" << uinum;
     qDebug() << "00000000000000000" << ceList->size();
    if(uinum == 1)
    {
      //  ce = ceList->at(ceList->size()-1);
      //  ce->ui->hide();
    }
    else
    {
    //    ceList->size();
    //    ce = ceList->at(uinum-1);
     //   ce->ui->hide();
    }
    ce = ceList->at(uinum);
    //ce->ui->show();
}

void CESelector_UI::on_pushButton_clicked()
{
    qDebug() << "pushButton";
    CE* ce;
    foreach(ce, *ceList)
    {
        //qDebug() << ce->ui->show();
        qDebug() << ceList->size();

        QString t;
        t.sprintf("CE type : %x, firstAttr %x, secondAttr : %x, thirdAttr : %x", ce->type, ce->firstAttr, ce->secondAttr, ce->thirdAttr);
        qDebug() << t;

        // 0x00 <TV> 0x01 <Refrigerator> 0x02 <Light> 0x03 <Heater> 0x04 <Cooler>

        switch(ce->type)
        {
            case 0x00:
            break;
            case 0x01:
            this->refrigeratorList->append(ce);
            break;
            case 0x02:
            this->lightList->append(ce);
            break;
            case 0x03:
            this->heaterList->append(ce);
            break;
            case 0x04:
            this->coolerList->append(ce);
            break;
            default:
            break;
        }

        //ce->ui->show();
    }

}
