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
    //ioInterface->getCeBuffer(); //TODO : list에 넣는 코드
    qDebug() << "HMManager getCeBuffer";
    qDebug() << ioInterface->getCeBuffer()->addr.toString();
    //this->ceList.insert(

    // TODO :  CE 구분해서 기존에 있는 CE일 경우 추가 안하게 해야 함.
    for(QList<CE>::iterator itor = this->ceList.begin(); itor != ceList.end(); itor++)
    {
        //qDebug() << "itor : " << itor.i;
    }

    this->ceList.append(*(ioInterface->getCeBuffer()));

    qDebug() << "list size : " << this->ceList.size();

    ioInterface->sendMessage(ioInterface->getCeBuffer()->socket, 0x00, ioInterface->getCeBuffer()->addr, 1106);


}
