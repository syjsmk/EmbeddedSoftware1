#include "hmmanager.h"

HMManager::HMManager()
{
    this->ioInterface = new IoInterface();

    QObject::connect(ioInterface, SIGNAL(getCeBufferSignal()), this, SLOT(getCeBuffer()));

}

HMManager::~HMManager()
{
    delete(ioInterface);
}

void HMManager::listenBroadcast()
{
    //this->ioInterface->listenBroadcast(this->ceList);
}

void HMManager::getCeBuffer()
{
    //ioInterface->getCeBuffer(); //TODO : list에 넣는 코드
    qDebug() << "FUCK";
    //qDebug() << ioInterface->getCeBuffer()->toString();


}
