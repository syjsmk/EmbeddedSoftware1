#ifndef CESELECTOR_UI_H
#define CESELECTOR_UI_H

#include <QtGui/QMainWindow>
#include <QUdpSocket>

#include "iointerface.h"

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
    QList<CE*> *ceList;

public:
    void setUiList(QList<CE*> *list);


private slots:
    void on_pushButton_clicked();
};

#endif // CESELECTOR_UI_H
