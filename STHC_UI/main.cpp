#include <QtGui/QApplication>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <signal.h>

#include "hmmanager.h"

#include "mysignal.h"
#include "tv_ui.h"
#include "iointerface.h"
#include "ceselector_ui.h"

void sig_handler(int signo, siginfo_t *info, void *context)
{
    int val = info->si_value.sival_int;
    qDebug() << "sigsigsigsigsigsigsigsigsigsig " << val;
    /*
    switch(val)
    {
        case IRQ_UP:
                TV_UI w;
                w.show();

            break;
        case IRQ_DOWN:
                TV_UI w;
                w.show();
            break;
        case IRQ_LEFT:
                CESelector_UI w;
                w.show();
            break;
        default:
            break;
    }
    */
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int dev, sthc_pid, ret;

    //setup_unix_signal_handlers();
     struct sigaction sigact;

    //    sigact.sa_sigaction =  IoInterface::signalHandler;
    //   sigact.sa_flags = SA_SIGINFO;
     //   sigaction(SIGUSR2, &sigact, NULL);

        sigact.sa_sigaction = sig_handler;
        sigact.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR2, &sigact, NULL);

    dev = open("/dev/switch_dev", O_RDWR);

    sthc_pid = getpid();

    qDebug() << "sthc_pid = " << sthc_pid;
    ret = ioctl(dev, signal_ioctl2, &sthc_pid);

    HMManager hmManager;
    hmManager.getCeList();

    CESelector_UI ceSelector;
    ceSelector.setUiList(hmManager.getCeList());
/*
    CE* ce;
    foreach(ce, *hmManager.getCeList())
    {
        //qDebug() << ce->ui->show();
        qDebug() << hmManager.getCeList()->size();
        ce->ui->show();
    }

    qDebug() << hmManager.getCeList()->size();
    */

    ceSelector.show();

/*
    TV_UI w;
    w.show();
    */

    return a.exec();
}
