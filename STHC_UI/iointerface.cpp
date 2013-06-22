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

 void IoInterface::signalHandler(int signo, siginfo_t *info, void *context)
 {
     //char a = 1;
    // ::write(sigusrFd[0], &a, sizeof(a));
      qDebug() << "sigsigsigsigsigsigsigsigsigsigisigsigsig";
 }

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

        //qDebug() << "device : " << device.data() << "    hex : " << device.toHex();

        QHostAddress itorAddr;

        this->CeBuffer = makeCeStruct(buffer.at(0), addr, port);
        emit getCeBufferSignal();
/*
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
*/
    }
}


//QHostAddress* IoInterface::getCeBuffer()
struct CE* IoInterface::getCeBuffer()
{
    qDebug() << "getCeBuffer";
    printCEInfo(*CeBuffer);
    return this->CeBuffer;
}

struct CE* IoInterface::makeCeStruct(char deviceType, QHostAddress addr, quint16 port)
{
    qDebug() << deviceType << "   hex :    " << deviceType;
    struct CE *CeBuff = new CE();
    CeBuff->addr = 0;
    CeBuff->socket = NULL;

    CeBuff->type = 0x00;
    CeBuff->firstAttr = 0x00;
    CeBuff->secondAttr = 0x00;
    CeBuff->thirdAttr = 0x00;



    CeBuff->type = deviceType;
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

    // 임시
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

    // 0x00 <TV> 3개
    // 0x01 <Refrigerator> 2개
    // 0x02 <Light> 2개
    // 0x03 <Heater> 3개
    // 0x04 <Cooler> 3개
//this->CeBuffer = CeBuff;
    switch(deviceType)
    {
        case 0x00:
        this->sendGetMessageEachAttribute(CeBuff, 3);
        break;
        case 0x01:
        this->sendGetMessageEachAttribute(CeBuff, 2);
        break;
        case 0x02:
        this->sendGetMessageEachAttribute(CeBuff, 2);
        break;
        case 0x03:
        this->sendGetMessageEachAttribute(CeBuff, 3);
        break;
        case 0x04:
        this->sendGetMessageEachAttribute(CeBuff, 3);
        break;
        default:
        break;
    }



    qDebug() << "CeBuffddddddddddddddddddddddddddddddddddddddd";
    printCEInfo(*CeBuff);
    printCEInfo(*CeBuffer);



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

        printMessageInfo(buffer);
/*
        getDeviceTypeFromMessage(buffer);
        getOperationTypeFromMessage(buffer);
        getOperationFromMessage(buffer);
        getOperandFromMessage(buffer);
*/
        if(getOperationTypeFromMessage(buffer) == 0xc0)
        {
            switch(getOperationFromMessage(buffer))
            {
                case 0x01:
                CeBuffer->firstAttr = getOperandFromMessage(buffer);
                break;
                case 0x02:
                CeBuffer->secondAttr = getOperandFromMessage(buffer);
                break;
                case 0x03:
                CeBuffer->thirdAttr = getOperandFromMessage(buffer);
                break;
                default:
                break;
            }
        }

        printCEInfo(*CeBuffer);

        emit initCompleteCeStructSignal();

    }

}

void IoInterface::sendGetMessageEachAttribute(CE *ce, int attributeCount)
{
    CeBuffer = ce;
    qDebug() << "sendGetMessageEachAttribute";
    QByteArray message;
    char attributeType = ATTRIBUTE_FIRST;

/*
    for(int i = 0; i < attributeCount; i ++)
        {
            message = this->makeMessage(ce->type, MESSAGE_OPTION_GET, attributeType, (char)0x00);
            sendMessage(ce->socket, message, ce->addr, 1106);
            attributeType ++;
        }
*/
    for(int i = 0; i < attributeCount; i ++)
    {
        message = this->makeMessage(CeBuffer->type, MESSAGE_OPTION_GET, attributeType, (char)0x00);
        sendMessage(CeBuffer->socket, message, CeBuffer->addr, 1106);
        attributeType ++;
    }
}

void IoInterface::printCEInfo(CE ce)
{
    QString t;
    t.sprintf("CE type : %x, firstAttr %x, secondAttr : %x, thirdAttr : %x", ce.type, ce.firstAttr, ce.secondAttr, ce.thirdAttr);
    qDebug() << t;
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
