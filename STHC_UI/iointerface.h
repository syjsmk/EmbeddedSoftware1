#ifndef IOINTERFACE_H
#define IOINTERFACE_H

#include <QUdpSocket>
#include <QObject>

class IoInterface : public QObject

{
    Q_OBJECT
public:
    IoInterface();
    ~IoInterface();

private :
    QUdpSocket *socket;

public slots:
  void broadcast();
};

#endif // IOINTERFACE_H
