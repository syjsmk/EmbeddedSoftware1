#include "hmmanager.h"

HMManager::HMManager()
{
    this->ioInterface = new IoInterface();
    QObject::connect(ioInterface, SIGNAL(getCeBufferSignal()), this, SLOT(getCeBuffer()));

}

HMManager::~HMManager()
{
    delete(ioInterface);
    this->ceList.clear();
}

void HMManager::listenBroadcast()
{
    //this->ioInterface->listenBroadcast(this->ceList);
}

void HMManager::getCeBuffer()
{
    bool isContain = false;
    qDebug() << "HMManager getCeBuffer";
    qDebug() << ioInterface->getCeBuffer()->addr.toString();


    CE ce;
    if(ceList.size() == 0)
    {
        this->ceList.append(*(ioInterface->getCeBuffer()));
    } else {
        foreach(ce, ceList)
        {
            qDebug() << "ce.addr : " << ce.addr << "iointerface.addr : " << ioInterface->getCeBuffer()->addr;
            if(ce.addr == ioInterface->getCeBuffer()->addr) {
                isContain = true;
            }
        }

        if(isContain == false)
        {
            this->ceList.append(*(ioInterface->getCeBuffer()));
        }
        isContain = false;
    }

    //this->ceList.append(*(ioInterface->getCeBuffer()));

    qDebug() << "ceList size : " << this->ceList.size();

    ioInterface->sendMessage(ioInterface->getCeBuffer()->socket, 0x00, ioInterface->getCeBuffer()->addr, 1106);


}
