#ifndef NETMANAGER_H
#define NETMANAGER_H

#include <QUdpSocket>
#include <QObject>

class netManager : public QObject

{
    Q_OBJECT
public:
    netManager();

private :
    QUdpSocket *socket;

private slots:
  void broadcast();
};

#endif // NETMANAGER_H
