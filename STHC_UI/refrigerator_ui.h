#ifndef REFRIGERATOR_UI_H
#define REFRIGERATOR_UI_H

#include <QtGui/QMainWindow>

#include "iointerface.h"

#include "ce.h"

namespace Ui {
    class Refrigerator_UI;
}

using namespace std;

class Refrigerator_UI : public QMainWindow {
    Q_OBJECT
public:
    Refrigerator_UI(QWidget *parent = 0);
    ~Refrigerator_UI();

    void setRefeigerator(CE *refrigerator);
    void initData();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Refrigerator_UI *m_ui;

    int power;
    int temperature;

    CE* refrigerator;
    IoInterface *ioInterface;


private slots:
    void on_tempDownButton_clicked();
    void on_tempUpButton_clicked();
    void on_powerButton_clicked();
};

#endif // REFRIGERATOR_UI_H
