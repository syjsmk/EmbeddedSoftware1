#ifndef HMMANAGER_H
#define HMMANAGER_H

#include <list>


#include "iointerface.h"
#include "ceselector_ui.h"

using namespace std;

class HMManager : public QObject
//class HMManager
{
    Q_OBJECT

public:
    HMManager();
    ~HMManager();

private:
    QList<CE*> *ceList;
    //list<CE> ceList;
    int curUI;
    int prevUI;
    IoInterface *ioInterface;

public:
    void listenBroadcast();
    //void sendMessage(QByteArray message);
    void sendMessage();
    QList<CE*> *getCeList();
    void selectorUI();
    void showTV();
    void showUI(int cur, int prev);

public slots:
    void getCeBuffer();
    void insertCE();
};

#endif // HMMANAGER_H
