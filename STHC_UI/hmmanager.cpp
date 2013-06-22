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
    //ioInterface->getCeBuffer(); //TODO : list에 넣는 코드
    qDebug() << "HMManager getCeBuffer";
    qDebug() << ioInterface->getCeBuffer()->addr.toString();
    //this->ceList.insert(

    // TODO :  CE 구분해서 기존에 있는 CE일 경우 추가 안하게 해야 함.

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

    qDebug() << "list size : " << this->ceList.size();

    ioInterface->sendMessage(ioInterface->getCeBuffer()->socket, 0x00, ioInterface->getCeBuffer()->addr, 1106);


}
