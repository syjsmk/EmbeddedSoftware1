#include "iointerface.h"
#include <QBitArray>

IoInterface::IoInterface()
{
    socket = new QUdpSocket(this);

    if(socket->bind(1106)) {
        qDebug() << "bind success";
    }

    connect( socket, SIGNAL(readyRead()), this, SLOT(listenBroadcast()) );
    //QObject::sender()->
    //connect(socket, SIGNAL(readyRead()), this, SLOT(listenBroadcast(list*)));
}

IoInterface::~IoInterface()
{
    delete(socket);
    delete this->CeBuffer;
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
        //CeBuffer = &addr;
        // signal

        this->CeBuffer = makeCeStruct((char)0x00, addr, port);

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


//QHostAddress* IoInterface::getCeBuffer()
struct CE* IoInterface::getCeBuffer()
{
    qDebug() << "getCeBuffer";
    qDebug() << CeBuffer->addr.toString();
    return this->CeBuffer;
}

struct CE* IoInterface::makeCeStruct(char deviceType, QHostAddress addr, quint16 port)
{
    struct CE *CeBuff = new CE();
    QUdpSocket *sock = new QUdpSocket();
    quint16 _port = 1107;

    // TODO : 빈 포트 할당
    if(sock->bind(_port)) {
        qDebug() << "makeCEStruct bind success";
    } else {
        qDebug() << "makeCEStruct bind fail";
    };
    CeBuff->socket = sock;
    CeBuff->addr = addr;
    qDebug() << "makeCeStruct addr : " << addr.toString();

    connect(CeBuff->socket, SIGNAL(readyRead()), this, SLOT(recvMessage()));
    qDebug() << QObject::sender();

 // writeDiagram 참고 코드
    //00421000  set 2번Attr 16
    // 마지막 1바이트가 사실상 필요가 없음.
    QByteArray message;
    message.resize(4);
    message.clear();

    message = this->makeMessage(0x00, MESSAGE_OPTION_SET, ATTRIBUTE_TEMPERATURE, (char)0x10);
    //message = this->makeMessage(0x00, MESSAGE_OPTION_GET, ATTRIBUTE_TEMPERATURE, (char)0x00);
    qDebug() << message.toHex();

    port = 1106;
    socket->writeDatagram(message, addr, port);

    message = this->makeMessage(0x00, MESSAGE_OPTION_GET, ATTRIBUTE_TEMPERATURE, (char)0x00);
    sendMessage(CeBuff->socket, message, addr, port);
    qDebug() << message.toHex();


    //socket->writeDatagram(message, addr, port);

    //TODO : 브로드캐스트 메시지에서 값 받아와서 얘 채워줘야 함
    //char deviceType = 'a';


    //int message = makeMessage(deviceType, MESSAGE_OPTION_GET, ATTRIBUTE_POWER, 0,addr, port);
    //sendMessage(message, addr, port);
    /*
    TODO : 내부에서 addr, port, makeMessage를 이용해
    broadcast를 보낸 기기에 getMessage를 만들어서 보내서
    CE의 정보를 받아서 받아온 값들을 이용해 CeBuff의 값을 채워줘야 한다.
       */

    return CeBuff;
}

// TODO :  이하의 함수들 구현해야 할 것. 반환형, 인자는 수정해도 상관 없음.
QByteArray IoInterface::makeMessage(char deviceType, char messageType, char attributeType, char operand)
{
    QByteArray message;

    if(messageType == 0x80)  //GET
    {
        message.append(deviceType);
        message.append(messageType|attributeType);
        message.append((char)0x00);
        message.append((char)0x00);

        return message;
    }
    if(messageType == 0x40)  //SET
    {
        message.append(deviceType);
        message.append(messageType|attributeType);
        // 0x00을 더 넣어서라도 4바이트 모양을 만들어 줘야 됨.
        message.append(operand);
        message.append((char)0x00);

        return message;
    }
}

void IoInterface::sendMessage(QUdpSocket *socket, QByteArray message, QHostAddress addr, quint16 port)
{
    qDebug() << "IoInterface::sendMessage start";
    qDebug() << "addr : " << addr.toString();

    socket->writeDatagram(message, addr, port);
    qDebug() << "IoInterface::sendMessage end";

}

void IoInterface::recvMessage()
{
    qDebug() << "recvMessage()";
    qDebug() << "CeBuffer->addr : " << CeBuffer->addr.toString();
    qDebug() << "datagramSize : " << CeBuffer->socket->pendingDatagramSize();

    QByteArray buffer(CeBuffer->socket->pendingDatagramSize(), 0);

    QObject *sender = const_cast<QObject*>(QObject::sender());
    QUdpSocket *sock = static_cast<QUdpSocket*>(sender);
    sock->readDatagram(buffer.data(), buffer.size());
    qDebug() << "bufferData : " << buffer.toHex();

}

