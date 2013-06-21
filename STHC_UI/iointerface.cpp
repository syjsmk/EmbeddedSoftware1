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
    //this->CeBuffer = new CE();


    if(socket->pendingDatagramSize() != -1){
        qDebug() << socket->pendingDatagramSize();
        socket->readDatagram(buffer.data(), buffer.size(), &addr, &port);


        QDataStream stream(buffer);
        qDebug() << "data = " << buffer.data() << " = " << buffer.toHex() << " addr : " << addr.toString() << " port : " << port << "size = " << buffer.count();
        //CeBuffer = &addr;
        // signal
        emit getCeBufferSignal();

        //TODO : 브로드캐스트 메시지에서 값 받아와서 얘 채워줘야 함
        char deviceType = 'a';

        this->CeBuffer = makeCeStruct(deviceType, addr, port);

        // writeDiagram 참고 코드
        //00421000
        QByteArray sendTemp;
        sendTemp.resize(4);
        sendTemp.clear();
        sendTemp.append((char)0x00);
        sendTemp.append((char)0x42);
        sendTemp.append((char)0x10);
        sendTemp.append((char)0x00);

        qDebug() << sendTemp.toHex();

        port = 1106;
        socket->writeDatagram(sendTemp, addr, port);


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
    return this->CeBuffer;
    //return this->CeBuffer;
}

struct CE* IoInterface::makeCeStruct(char deviceType, QHostAddress addr, quint16 port)
{
    struct CE *CeBuff = new CE();



    int message = makeMessage(deviceType, MESSAGE_OPTION_GET, ATTRIBUTE_POWER, addr, port);
    sendMessage(message, addr, port);
    /*
    TODO : 내부에서 addr, port, makeMessage를 이용해
    broadcast를 보낸 기기에 getMessage를 만들어서 보내서
    CE의 정보를 받아서 받아온 값들을 이용해 CeBuff의 값을 채워줘야 한다.
       */

    return CeBuff;
}

// TODO :  이하의 함수들 구현해야 할 것. 반환형, 인자는 수정해도 상관 없음.
int IoInterface::makeMessage(char deviceType, char messageType, char attributeType, QHostAddress addr, quint16 port)
{
}

void IoInterface::sendMessage(int message, QHostAddress addr, quint16 port)
{
    //this->socket->writeDatagram()
}

// TODO : get메시지에 대한 패킷은 broadcast가 아니라 unicast니까 위의 리스너가 받지 못함.
// TODO : 동적으로 소켓을 생성해야 한다고 함. 또 connect 써야 함. unicast용 소켓은 1106이 아니라 다른걸 써서 받아야 함.
void IoInterface::recvMessage()
{
}
