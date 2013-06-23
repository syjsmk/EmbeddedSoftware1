

#include <QUdpSocket>
#include <QtGui/QMainWindow>

#define NOUSE   0xFF

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

    QMainWindow* ui;

    QHostAddress addr;
    QUdpSocket *socket;
};
