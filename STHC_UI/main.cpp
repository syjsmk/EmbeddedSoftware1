#include <QtGui/QApplication>
#include "tv_ui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TV_UI w;
    w.show();
    return a.exec();
}
