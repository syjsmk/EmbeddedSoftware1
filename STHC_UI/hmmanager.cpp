#include "hmmanager.h"

HMManager::HMManager()
{
    this->ioInterface = new IoInterface();
}

HMManager::~HMManager()
{
    delete(ioInterface);
}

void HMManager::listenBroadcast()
{
    //this->ioInterface->listenBroadcast(this->ceList);
}
