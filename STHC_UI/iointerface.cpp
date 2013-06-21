#include "iointerface.h"

IoInterface::IoInterface()
{
    socket = new QUdpSocket(this);

    if(socket->bind(1106)) {
        qDebug() << "bind success";
    }

    connect( socket, SIGNAL(readyRead()), this, SLOT(broadcast()) );
}

IoInterface::~IoInterface()
{
    delete(socket);
}

void IoInterface::broadcast()
{

    qDebug() << "broadCast()";
    QByteArray buffer(socket->pendingDatagramSize(), 0);
    QHostAddress addr;
    quint16 port;
    


    if(socket->pendingDatagramSize() != -1){
        qDebug() << socket->pendingDatagramSize();
        socket->readDatagram(buffer.data(), buffer.size(), &addr, &port);


        QDataStream stream(buffer);
        qDebug() << "data = " << buffer.data() << " hex = " << buffer.toHex() << " addr : " << addr.toString() << " port : " << port;
    }


}
