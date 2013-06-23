#include "hmmanager.h"

HMManager::HMManager()
{
    ceList = new QList<CE*>;

    this->ioInterface = new IoInterface();
    QObject::connect(ioInterface, SIGNAL(getCeBufferSignal()), this, SLOT(getCeBuffer()));
    QObject::connect(ioInterface, SIGNAL(initCompleteCeStructSignal()), this, SLOT(insertCE()));

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
