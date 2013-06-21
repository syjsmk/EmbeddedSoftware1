#include "iointerface.h"
#include <QBitArray>

IoInterface::IoInterface()
{
    socket = new QUdpSocket(this);

    if(socket->bind(1106)) {
        qDebug() << "bind success";
    }

    connect( socket, SIGNAL(readyRead()), this, SLOT(listenBroadcast()) );
    //connect(socket, SIGNAL(readyRead()), this, SLOT(listenBroadcast(list*)));
}

IoInterface::~IoInterface()
{
    delete(socket);
}

QBitArray bytesToBits(QByteArray bytes) {
    QBitArray bits(bytes.count()*8);
    // Convert from QByteArray to QBitArray
    for(int i=0; i<bytes.count(); ++i)
    {
        for(int b=0; b<8; ++b)
        {
            bits.setBit(i*8+b, bytes.at(i)&(1<<b));
            qDebug() << "data = " << bits.at(i);
        }
    }
    return bits;
}


QByteArray bitsToBytes(QBitArray bits) {
    QByteArray bytes;
    bytes.resize(bits.count()/8+1);
    bytes.fill(0);
    // Convert from QBitArray to QByteArray
    for(int b=0; b<bits.count(); ++b)
        bytes[b/8] = ( bytes.at(b/8) | ((bits[b]?1:0)<<(b%8)));
    return bytes;
}


void IoInterface::listenBroadcast()
//void IoInterface::listenBroadcast(list *outParamList)
{
    QBitArray bits;
    qDebug() << "broadCast()";
    QByteArray buffer(socket->pendingDatagramSize(), 0);
    QByteArray device;
    QByteArray optype;
    QByteArray op;
    QByteArray opd;

    QHostAddress addr;
    quint16 port;


    if(socket->pendingDatagramSize() != -1){
        qDebug() << socket->pendingDatagramSize();
        socket->readDatagram(buffer.data(), buffer.size(), &addr, &port);

        QDataStream stream(buffer);
        qDebug() << "data = " << buffer.data() << " = " << buffer.toHex() << " addr : " << addr.toString() << " port : " << port << "size = " << buffer.count();
        CeBuffer = &addr;
        // signal
        emit getCeBufferSignal();

        switch(buffer.count())
        {
            case 2:
                device.append(buffer.at(0)&0xFF);
                qDebug() << "data = " << device.data() << device.toHex();
                break;
            case 3:
                device.append(buffer.at(0)&0xFF);
                optype.append((buffer.at(1)&0xC0)>>6);
                op.append(buffer.at(1)&0x3F);
                qDebug() << "device = " << device.data() << device.toHex();
                qDebug() << "optype = " << optype.data() << optype.toHex();
                qDebug() << "op = " << op.data() << op.toHex();
                break;
            case 4:
                device.append(buffer.at(0)&0xFF);
                optype.append((buffer.at(1)&0xC0)>>6);
                op.append(buffer.at(1)&0x3F);
                opd.append(buffer.right(2));
                qDebug() << "device = " << device.data() << device.toHex();
                qDebug() << "optype = " << optype.data() << optype.toHex();
                qDebug() << "op = " << op.data() << op.toHex();
                qDebug() << "opd = " << opd.data() << opd.toHex();
                break;
            default:
                break;
        }
    }
}


QHostAddress* IoInterface::getCeBuffer()
{
    return this->CeBuffer;
}
