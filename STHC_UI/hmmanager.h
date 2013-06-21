#ifndef HMMANAGER_H
#define HMMANAGER_H

#include <list>
#include "ce.h"

using namespace std;

class HMManager
{
public:
    HMManager();

private:
    list<CE> ceList;
};

#endif // HMMANAGER_H
