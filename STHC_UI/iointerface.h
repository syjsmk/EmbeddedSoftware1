#ifndef IOINTERFACE_H
#define IOINTERFACE_H


#include <QUdpSocket>
#include <QObject>
#include <QBitArray>

#include "ce.h"

// TODO : 얘네 다른 파일에 일괄적으로 정의해야 할 필요 있을듯 함
#define MESSAGE_OPTION_GET  'b'
#define ATTRIBUTE_POWER         'c'


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
    struct CE* makeCeStruct(char deviceType, QHostAddress addr, quint16 port);

    int makeMessage(char deviceType, char messageType, char attributeType, QHostAddress addr, quint16 port);
    void sendMessage(int message, QHostAddress addr, quint16 port);
    void recvMessage();

public slots:
  void listenBroadcast();


  signals:
    void getCeBufferSignal();

};

#endif // IOINTERFACE_H
