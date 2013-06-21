#ifndef TV_UI_H
#define TV_UI_H

#include <QtGui/QMainWindow>

#include <QUdpSocket>
#include "netmanager.h"

namespace Ui
{
    class TV_UI;
}

class TV_UI : public QMainWindow
{
    Q_OBJECT

public:
    TV_UI(QWidget *parent = 0);
    ~TV_UI();

private:
    Ui::TV_UI *ui;

    // 변수들 초기화 하려면
    // 패킷 받아서 그 값으로 해야 함.
    bool power;
    int channel;
    int volume;

    netManager *netMgr;
    QUdpSocket *socket;

private slots:
    void on_volDownButton_clicked();
    void on_volUpButton_clicked();
    void on_chDownButton_clicked();
    void on_chUpButton_clicked();
    void on_powerButton_clicked();

    void temp();
};

#endif // TV_UI_H
