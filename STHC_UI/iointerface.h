#ifndef IOINTERFACE_H
#define IOINTERFACE_H

#include <QUdpSocket>
#include <QObject>
#include <QBitArray>

// TODO : 여기 내부에 ioctl, udp 관련 코드 들어가야 함.

class IoInterface : public QObject

{
    Q_OBJECT
public:
    IoInterface();
    ~IoInterface();

private :
    QUdpSocket *socket;

public slots:
  void listenBroadcast();
};

#endif // IOINTERFACE_H
