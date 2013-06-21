#ifndef CESELECTOR_UI_H
#define CESELECTOR_UI_H

#include <QtGui/QMainWindow>
#include <QUdpSocket>

#include "netmanager.h"

namespace Ui {
    class CESelector_UI;
}

class CESelector_UI : public QMainWindow {
    Q_OBJECT
public:
    CESelector_UI(QWidget *parent = 0);
    ~CESelector_UI();

private:
    Ui::CESelector_UI *ui;

};

#endif // CESELECTOR_UI_H
