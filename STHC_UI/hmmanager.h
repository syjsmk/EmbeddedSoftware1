#ifndef HMMANAGER_H
#define HMMANAGER_H

#include <list>
#include "ce.h"

#include "iointerface.h"

using namespace std;

class HMManager
{
public:
    HMManager();
    ~HMManager();

private:
    list<CE> ceList;

    IoInterface *ioInterface;

public:
    void listenBroadcast();
};

#endif // HMMANAGER_H
