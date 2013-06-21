#include "netmanager.h"

netManager::netManager()
{
    socket = new QUdpSocket();
    socket->bind(1106);
    connect( socket, SIGNAL(readReady()), this, SLOT(broadcast()) );
}

void netManager::broadcast()
{

}
