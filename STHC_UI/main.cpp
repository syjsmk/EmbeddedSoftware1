#include <QtGui/QApplication>
#include "hmmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HMManager w;
    w.show();
    return a.exec();
}
