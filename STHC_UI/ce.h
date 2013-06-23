#ifndef CE_H
#define CE_H

#include <QUdpSocket>

typedef struct CE
{
    /*
    int type;
    bool power;
    QHostAddress addr;

    int temperature;
    int wind;
    int brightness;
    int volume;
    int channel;

    QUdpSocket *socket;

    */
    char type;
    char firstAttr; // power
    char secondAttr; // channel, temperature, brightness
    char thirdAttr; // volume, wind
    int dev;
    QHostAddress addr;
    QUdpSocket *socket;
};


#endif
