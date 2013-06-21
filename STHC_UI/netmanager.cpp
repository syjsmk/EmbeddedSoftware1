#include "netmanager.h"

netManager::netManager()
{
    socket = new QUdpSocket(this);

    if(socket->bind(1106)) {
        qDebug() << "bind success";
    }

    connect( socket, SIGNAL(readyRead()), this, SLOT(broadcast()) );
}

netManager::~netManager()
{
    delete(socket);
}

void netManager::broadcast()
{

    qDebug() << "broadCast()";
    QByteArray buffer(socket->pendingDatagramSize(), 0);


    if(socket->pendingDatagramSize() != -1){
        qDebug() << socket->pendingDatagramSize();
        socket->readDatagram(buffer.data(), buffer.size());

        QDataStream stream(buffer);
        qDebug() << "data = " << buffer.data() << " = " << hex << buffer.data();
    }


}
