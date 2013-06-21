#ifndef IOINTERFACE_H
#define IOINTERFACE_H


#include <QUdpSocket>
#include <QObject>
#include <QBitArray>

#include "ce.h"


// TODO : 여기 내부에 ioctl, udp 관련 코드 들어가야 함.

class IoInterface : public QObject

{
    Q_OBJECT
public:
    IoInterface();
    ~IoInterface();

private :
    QUdpSocket *socket;

    //QHostAddress *CeBuffer;
    struct CE *CeBuffer;

public:
    //QHostAddress *getCeBuffer();
    struct CE *getCeBuffer();
    struct CE* makeCeStruct(QHostAddress addr, quint16 port);

    void makeMessage();
    void sendMessage();
    void recvMessage();

public slots:
  void listenBroadcast();


  signals:
    void getCeBufferSignal();

};

#endif // IOINTERFACE_H
