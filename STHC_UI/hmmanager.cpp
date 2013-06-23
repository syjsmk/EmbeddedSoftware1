#include "hmmanager.h"

HMManager::HMManager()
{
    ceList = new QList<CE*>;
    curUI = 0;
    prevUI = 0;
    this->ioInterface = new IoInterface();
  //  this->ceSelector = new CESelector_UI();

    QObject::connect(ioInterface, SIGNAL(getCeBufferSignal()), this, SLOT(getCeBuffer()));
    QObject::connect(ioInterface, SIGNAL(initCompleteCeStructSignal()), this, SLOT(insertCE()));

    this->tvUi = new TV_UI();
    this->coolerUi = new Cooler_UI();
    this->heaterUi = new Heater_UI();
    this->lightUi = new Light_UI();
    this->refrigeratorUi = new Refrigerator_UI();

}

HMManager::~HMManager()
{
    delete(ioInterface);
    this->ceList->clear();
    delete ceList;
}

void HMManager::listenBroadcast()
{
    //this->ioInterface->listenBroadcast(this->ceList);
}

void HMManager::insertCE()
{

}
void HMManager::showUI(int cur, int prev)
{
    CE* ce;
    qDebug() << "ceList Size : " << ceList->size() << "cur : " << cur << "prev : " << prev;

    QString t;


    if(ceList->size() == 1)
    {
        ce = ceList->at(cur);
        t.sprintf("CE type : %x, firstAttr %x, secondAttr : %x, thirdAttr : %x", ce->type, ce->firstAttr, ce->secondAttr, ce->thirdAttr);
        qDebug() << t;

        //ce->ui->show();
        char deviceType = ce->type;
        switch(deviceType)
        {
            case 0x00:
                qDebug() << "Device <TV>";
                tvUi->setTv(ce);
                tvUi->show();
                refrigeratorUi->hide();
                lightUi->hide();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x01:
                qDebug() << "Device <Refrigerator>";
                refrigeratorUi->setRefeigerator(ce);
                tvUi->hide();
                refrigeratorUi->show();
                lightUi->hide();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x02:
                qDebug() << "Device <Light>";
                lightUi->setLight(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->show();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x03:
                qDebug() << "Device <Heater>";
                heaterUi->setHeater(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->hide();
                heaterUi->show();
                coolerUi->hide();
            break;
            case 0x04:
                qDebug() << "Device <Cooler>";
                coolerUi->setCooler(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->hide();
                coolerUi->show();
            break;
            default:
            break;
        }

    }
    if(ceList->size() > 1)
    {
        ce = ceList->at(prev);

        t.sprintf("CE type : %x, firstAttr %x, secondAttr : %x, thirdAttr : %x", ce->type, ce->firstAttr, ce->secondAttr, ce->thirdAttr);
        qDebug() << t;

        char deviceType = ce->type;
        switch(deviceType)
        {
            case 0x00:
                qDebug() << "Device <TV>";
                tvUi->setTv(ce);
                tvUi->show();
                refrigeratorUi->hide();
                lightUi->hide();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x01:
                qDebug() << "Device <Refrigerator>";
                refrigeratorUi->setRefeigerator(ce);
                tvUi->hide();
                refrigeratorUi->show();
                lightUi->hide();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x02:
                qDebug() << "Device <Light>";
                lightUi->setLight(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->show();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x03:
                qDebug() << "Device <Heater>";
                heaterUi->setHeater(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->hide();
                heaterUi->show();
                coolerUi->hide();
            break;
            case 0x04:
                qDebug() << "Device <Cooler>";
                coolerUi->setCooler(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->hide();
                coolerUi->show();
            break;
            default:
            break;
        }

        //ce->ui->hide();
    }
    ce = ceList->at(cur);

    t.sprintf("CE type : %x, firstAttr %x, secondAttr : %x, thirdAttr : %x", ce->type, ce->firstAttr, ce->secondAttr, ce->thirdAttr);
    qDebug() << t;

    char deviceType = ce->type;
        switch(deviceType)
        {
            case 0x00:
                qDebug() << "Device <TV>";
                tvUi->setTv(ce);
                tvUi->show();
                refrigeratorUi->hide();
                lightUi->hide();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x01:
                qDebug() << "Device <Refrigerator>";
                refrigeratorUi->setRefeigerator(ce);
                tvUi->hide();
                refrigeratorUi->show();
                lightUi->hide();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x02:
                qDebug() << "Device <Light>";
                lightUi->setLight(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->show();
                heaterUi->hide();
                coolerUi->hide();
            break;
            case 0x03:
                qDebug() << "Device <Heater>";
                heaterUi->setHeater(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->hide();
                heaterUi->show();
                coolerUi->hide();
            break;
            case 0x04:
                qDebug() << "Device <Cooler>";
                coolerUi->setCooler(ce);
                tvUi->hide();
                refrigeratorUi->hide();
                lightUi->hide();
                coolerUi->show();
            break;
            default:
            break;
        }

    //ce->ui->show();


}

void HMManager::selectorUI()
{
    prevUI = curUI;
    curUI++;
    if(curUI >= ceList->size())
    {
        curUI = 0;
    }
    showUI(curUI, prevUI);
}

void HMManager::showTV()
{
    prevUI = curUI;
    curUI = 0;
    showUI(curUI, prevUI);
}

void HMManager::getCeBuffer()
{
    bool isContain = false;

    CE* ce;
    if(ceList->size() == 0)
    {
        this->ceList->append((ioInterface->getCeBuffer()));
    } else {
        foreach(ce, *ceList)
        {
            if(ce->addr == ioInterface->getCeBuffer()->addr) {
                isContain = true;
            }
        }

        if(isContain == false)
        {
            this->ceList->append((ioInterface->getCeBuffer()));
        }
        isContain = false;
    }
}


void HMManager::sendMessage()
{
    qDebug() << "sendMessage in HM";
    CE* ce;
    QByteArray message;

    message = this->ioInterface->makeMessage((char)0x03, MESSAGE_OPTION_GET, ATTRIBUTE_FIRST, (char)0x00);
    ioInterface->printMessageInfo(message);

    foreach(ce, *ceList)
    {
        this->ioInterface->sendMessage(ce->socket, message, ce->addr, 1106);
    }
}

QList<CE*>* HMManager::getCeList()
{
    return this->ceList;
}
