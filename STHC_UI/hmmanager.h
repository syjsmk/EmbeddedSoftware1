#ifndef HMMANAGER_H
#define HMMANAGER_H

#include <QObject>
#include <list>


#include "iointerface.h"

using namespace std;

class HMManager : public QObject
//class HMManager
{
    Q_OBJECT

public:
    HMManager();
    ~HMManager();

private:
    QList<CE> ceList;
    //list<CE> ceList;

    IoInterface *ioInterface;

public:
    void listenBroadcast();

public slots:
    void getCeBuffer();
};

#endif // HMMANAGER_H
