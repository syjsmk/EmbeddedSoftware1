

#include <QUdpSocket>

#define NOUSE   999

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

    QUdpSocket *socket;
    
    CE()
    {
        temperature = NOUSE;
        wind = NOUSE;
        brightness = NOUSE;
        volume = NOUSE;
        channel = NOUSE;
    }
};
