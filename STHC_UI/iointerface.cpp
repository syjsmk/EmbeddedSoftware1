#include "iointerface.h"
#include <QBitArray>

// TODO : recvManager 호출 횟수가 하나씩 늘어남. 뭐가 문제인가

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

// TODO : IP주소 중복 처리
void IoInterface::listenBroadcast()
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
        device.append(buffer.at(0)&0xFF);

        qDebug() << "device : " << device.data() << "    hex : " << device.toHex();

        QHostAddress itorAddr;

        this->CeBuffer = makeCeStruct(buffer.at(0), addr, port);
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
    //qDebug() << "getCeBuffer";
    //qDebug() << CeBuffer->addr.toString();
    return this->CeBuffer;
}

struct CE* IoInterface::makeCeStruct(char deviceType, QHostAddress addr, quint16 port)
{
    qDebug() << deviceType << "   hex :    " << deviceType;
    struct CE *CeBuff = new CE();
    QUdpSocket *sock = new QUdpSocket();

    quint16 _port = 0;

    if(ipSocketHashmap.size() == 0)
    {
        qDebug() << "hashMapSize zero";
        sock = new QUdpSocket();

        connect(sock, SIGNAL(readyRead()), this, SLOT(recvMessage()));
        ipSocketHashmap.insert(addr, sock);

        if(sock->bind(_port)) {
            qDebug() << "makeCEStruct bind success";
        } else {
            qDebug() << "makeCEStruct bind fail";
        };
    } else {

        if(ipSocketHashmap.contains(addr)) {
            sock = ipSocketHashmap.value(addr);
            qDebug() << "already exist IP";
        } else {
            qDebug() << "not exist";
            sock = new QUdpSocket();
            connect(sock, SIGNAL(readyRead()), this, SLOT(recvMessage()));
            ipSocketHashmap.insert(addr, sock);

            if(sock->bind(_port)) {
                qDebug() << "makeCEStruct bind success";
            } else {
                qDebug() << "makeCEStruct bind fail";
            };
        }
    }

    qDebug() << "ipSocketHashmap Size : " << ipSocketHashmap.size();

    CeBuff->socket = sock;
    CeBuff->addr = addr;
    qDebug() << "makeCeStruct addr : " << addr.toString();

    CeBuff->firstAttr = 0x01;
    QString t;
    t.sprintf("first Attr : %x", CeBuff->firstAttr);
    qDebug() << t;

    //connect(CeBuff->socket, SIGNAL(readyRead()), this, SLOT(recvMessage()));

 // writeDiagram 참고 코드
    //00421000  set 2번Attr 16
    // 마지막 1바이트가 사실상 필요가 없음.
    QByteArray message;
    message.resize(4);
    message.clear();
    port = 1106;

    //CeBuff->type = deviceType;
    //CeBuff->type = getDeviceTypeFromMessage(message);

    // 0x00 <TV> 3개
    // 0x01 <Refrigerator> 2개
    // 0x02 <Light> 2개
    // 0x03 <Heater> 3개
    // 0x04 <Cooler> 3개
    switch(deviceType)
    {
        case 0x00:

        break;
        case 0x01:
        break;
        case 0x02:
        break;
        case 0x03:
        break;
        case 0x04:
        break;
        default:
        break;
    }

    /*
    if(deviceType == 0x03) {
        qDebug() << "0x03 --------------------------------------------------";

        message = this->makeMessage(deviceType, MESSAGE_OPTION_GET, ATTRIBUTE_FIRST, (char)0x00);
        printMessageInfo(message);
        sendMessage(CeBuff->socket, message, addr, port);


        message = this->makeMessage(deviceType, MESSAGE_OPTION_GET, ATTRIBUTE_SECOND, (char)0x00);
        printMessageInfo(message);
        sendMessage(CeBuff->socket, message, addr, port);


        message = this->makeMessage(deviceType, MESSAGE_OPTION_GET, ATTRIBUTE_THIRD, (char)0x00);
        printMessageInfo(message);
        sendMessage(CeBuff->socket, message, addr, port);

    }
    */


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

        qDebug() << "type GET : " << message.toHex() << "size : " << message.size();

        return message;
    }
    if(messageType == 0x40)  //SET
    {
        message.append(deviceType);
        message.append(messageType|attributeType);
        // 0x00을 더 넣어서라도 4바이트 모양을 만들어 줘야 됨.
        message.append(operand);
        message.append((char)0x00);

        qDebug() << "type SET : " << message.toHex() << "size : " << message.size();

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
    qDebug() << CeBuffer->addr.toString();
    QString t;
    t.sprintf("first Attr : %x", CeBuffer->firstAttr);
    qDebug() << t;


    if(CeBuffer->socket->pendingDatagramSize() > 0)
    {
        qDebug() << "datagramSize : " << CeBuffer->socket->pendingDatagramSize();
        QByteArray buffer(CeBuffer->socket->pendingDatagramSize(), 0);

        QObject *sender = const_cast<QObject*>(QObject::sender());
        QUdpSocket *sock = static_cast<QUdpSocket*>(sender);
        sock->readDatagram(buffer.data(), buffer.size());

        /*
        char operation = buffer.at(1) & 0x0F;
        qDebug() << "operand : " << (buffer.at(1) & 0x0F);
        */
        printMessageInfo(buffer);
/*
        getDeviceTypeFromMessage(buffer);
        getOperationTypeFromMessage(buffer);
        getOperationFromMessage(buffer);
        getOperandFromMessage(buffer);
*/
    }

}

void IoInterface::printDevice(char deviceType)
{
    switch(deviceType)
    {
        case 0x00:
            qDebug() << "Device <TV>";
        break;
        case 0x01:
            qDebug() << "Device <Refrigerator>";
        break;
        case 0x02:
            qDebug() << "Device <Light>";
        break;
        case 0x03:
            qDebug() << "Device <Heater>";
        break;
        case 0x04:
            qDebug() << "Device <Cooler>";
        break;
        default:
        break;
    }
}

void IoInterface::printMessageInfo(QByteArray message)
{
    qDebug() << "printMessageInfo";
    QString temp;

    // 0x00 <TV> 0x01 <Refrigerator> 0x02 <Light> 0x03 <Heater> 0x04 <Cooler>
    char deviceType = (message.at(0) & 0xff);
    switch(deviceType)
    {
        case 0x00:
            qDebug() << "Device <TV>";
        break;
        case 0x01:
            qDebug() << "Device <Refrigerator>";
        break;
        case 0x02:
            qDebug() << "Device <Light>";
        break;
        case 0x03:
            qDebug() << "Device <Heater>";
        break;
        case 0x04:
            qDebug() << "Device <Cooler>";
        break;
        default:
        break;
    }

    // 0x00 <broadcast> 0x40 <set> 0x80 <get> 0xC0 <res for get>
    char operationType = (message.at(1) & 0xf0);
    switch(operationType)
    {
        case 0x00:
            qDebug() << "operation <broadcast>";
        break;
        case 0x40:
            qDebug() << "operation <set>";
        break;
        case 0x80:
            qDebug() << "operation <get>";
        break;
        case 0xc0:
            qDebug() << "operation <res for get>";
        break;
        default:
        break;
    }

    char operation = message.at(1) & 0x0F;

    // 0x00, 0x01, 0x02, 0x03
    switch(operation)
    {
        case 0x00:
            qDebug() << "ATTR_0";
        break;
        case 0x01:
            qDebug() << "ATTR_1";
        break;
        case 0x02:
            qDebug() << "ATTR_2";
        break;
        case 0x03:
            qDebug() << "ATTR_3";
        break;
        default:
        break;
    }

    char operand = message.at(2) & 0xff;
    qDebug() << operand;

}

char IoInterface::getDeviceTypeFromMessage(QByteArray message)
{
    char deviceType = (message.at(0) & 0xff);
    switch(deviceType)
    {
        case 0x00:
            qDebug() << "Device <TV>";
        break;
        case 0x01:
            qDebug() << "Device <Refrigerator>";
        break;
        case 0x02:
            qDebug() << "Device <Light>";
        break;
        case 0x03:
            qDebug() << "Device <Heater>";
        break;
        case 0x04:
            qDebug() << "Device <Cooler>";
        break;
        default:
        break;
    }
    
    return deviceType;
}

char IoInterface::getOperationTypeFromMessage(QByteArray message)
{
    // 0x00 0x40 0x80 0xC0
    char operationType = (message.at(1) & 0xf0);
    switch(operationType)
    {
        case 0x00:
            qDebug() << "operation <broadcast>";
        break;
        case 0x40:
            qDebug() << "operation <set>";
        break;
        case 0x80:
            qDebug() << "operation <get>";
        break;
        case 0xc0:
            qDebug() << "operation <res for get>";
        break;
        default:
        break;
    }

    return operationType;
}

char IoInterface::getOperationFromMessage(QByteArray message)
{
    char operation = message.at(1) & 0x0F;

    // 0x00, 0x01, 0x02, 0x03
    switch(operation)
    {
        case 0x00:
            qDebug() << "ATTR_0";
        break;
        case 0x01:
            qDebug() << "ATTR_1";
        break;
        case 0x02:
            qDebug() << "ATTR_2";
        break;
        case 0x03:
            qDebug() << "ATTR_3";
        break;
        default:
        break;
    }
    return operation;
}

char IoInterface::getOperandFromMessage(QByteArray message)
{
    char operand = message.at(2) & 0xff;
    return operand;
}
