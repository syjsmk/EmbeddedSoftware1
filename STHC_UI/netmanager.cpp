#include "netmanager.h"

netManager::netManager()
{
    socket = new QUdpSocket(this);

    if(socket->bind(1106)) {
        qDebug() << "bind success";
    }

    connect( socket, SIGNAL(readReady()), this, SLOT(broadcast()) );
}

netManager::~netManager()
{
    delete(socket);
}

void netManager::broadcast()
{

    qDebug() << "broadCast()";
    qDebug() << socket->pendingDatagramSize();

}
