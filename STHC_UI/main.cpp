#include <QtGui/QApplication>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <signal.h>

#include "hmmanager.h"
#include "mysignal.h"
#include "ceselector_ui.h"

#define MAXCH 0x0D
#define MINCH 0x01
void *buf;

void sig_handler(int signo, siginfo_t *info, void *context)
{
    //uiStruct val;
    int val = info->si_value.sival_int;
    HMManager *hmmanager = (HMManager*)buf;

    CE *ce;

    switch(val)
    {
        case IRQ_UP:
             qDebug() << "Switch Up";
             foreach(ce, *(hmmanager->getCeList()))
             {
                 if(ce->addr.toString().compare("0.0.0.0") == 0)
                 {
                     if(ce->secondAttr + 0x01 > MAXCH)
                     {
                         ce->secondAttr = MINCH;
                     }
                     else
                         ce->secondAttr += 0x01;
                 }
             }
             hmmanager->showTV();
            break;
        case IRQ_DOWN:
             qDebug() << "Switch Down";
             foreach(ce, *(hmmanager->getCeList()))
             {
                 if(ce->addr.toString().compare("0.0.0.0") == 0)
                 {
                     if(ce->secondAttr - 0x01 < MINCH)
                     {
                         ce->secondAttr = MAXCH;
                     }
                     else
                         ce->secondAttr -= 0x01;
                 }
             }
             hmmanager->showTV();
            break;
        case IRQ_LEFT:
             qDebug() << "Switch Left";
                hmmanager->selectorUI();
            break;
        default:
            break;
    }

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int dev, sthc_pid, ret;

    struct sigaction sigact;
    HMManager *hmManager = new HMManager();
    buf = hmManager;

    sigact.sa_sigaction = sig_handler;
    sigact.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sigact, NULL);

    dev = open("/dev/switch_dev", O_RDWR);

    sthc_pid = getpid();

    qDebug() << "sthc_pid = " << sthc_pid;
    ret = ioctl(dev, signal_ioctl2, &sthc_pid);

    CE *tv = new CE();
    tv->addr = QHostAddress ("0.0.0.0");
    tv->secondAttr = 0x05;
    tv->thirdAttr = 0x32;
    tv->dev = dev;
    //tv->ui = new TV_UI();


    hmManager->getCeList()->append(tv);


    hmManager->showTV();

    return a.exec();
}
