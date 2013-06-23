#ifndef IOINTERFACE_H
#define IOINTERFACE_H


#include <QUdpSocket>
#include <QObject>
#include <QBitArray>
#include <signal.h>

#include "ce.h"
#include "MessageDefine.h"

#include "tv_ui.h"
#include "cooler_ui.h"
#include "heater_ui.h"
#include "light_ui.h"
#include "refrigerator_ui.h"
#include "tv_ui.h"

// TODO : 얘네 다른 파일에 일괄적으로 정의해야 할 필요 있을듯 함



// TODO : 여기 내부에 ioctl, udp 관련 코드 들어가야 함.

class IoInterface : public QObject

{
    Q_OBJECT
public:
    IoInterface();
    ~IoInterface();

private :
    QUdpSocket *socket;
    QHash<QHostAddress, QUdpSocket*> ipSocketHashmap;

    //QHostAddress *CeBuffer;
    struct CE *CeBuffer;


    char getDeviceTypeFromMessage(QByteArray message);
    char getOperationTypeFromMessage(QByteArray message);
    char getOperationFromMessage(QByteArray message);
    char getOperandFromMessage(QByteArray message);
    void sendGetMessageEachAttribute(CE *ce, int attributeCount);

public:
    //QHostAddress *getCeBuffer();
    void printMessageInfo(QByteArray message);
    struct CE *getCeBuffer();
    struct CE* makeCeStruct(char deviceType, QHostAddress addr, quint16 port);

    QByteArray makeMessage(char deviceType, char messageType, char attributeType, char operand);
    void sendMessage(QUdpSocket *socket, QByteArray message, QHostAddress addr, quint16 port);
    void printCEInfo(CE ce);
    //void recvMessage();
    void signalHandler(int signo, siginfo_t *info, void *context);

public slots:
  void listenBroadcast();
  void recvMessage();

  signals:
    void getCeBufferSignal();
    void initCompleteCeStructSignal();

};

#endif // IOINTERFACE_H
