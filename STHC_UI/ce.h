

#include <QUdpSocket>

typedef struct CE
{
    int type;
    bool power;
    QHostAddress addr;

    int temperature;
    int wind;
    int brightness;
    int volume;
    int channel;

    //QUdpSocket *socket;
};
