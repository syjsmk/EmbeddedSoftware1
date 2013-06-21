#include "ceselector_ui.h"
#include "ui_ceselector_ui.h"

CESelector_UI::CESelector_UI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CESelector_UI)
{
    ui->setupUi(this);
    // 여기 내부에서 connect 써야 할 것 같음.
    // http://stackoverflow.com/questions/5027406/how-to-move-to-another-window-in-qt-by-a-pushbutton

    /*
    this->netMgr = new netManager();
    netMgr->broadcast();
    */
    this->sock = new QUdpSocket(this);

   qDebug() << "CESelector creator";

    if(sock->bind(1106)) {
        qDebug() << "bind success";
    }

    connect(this->sock, SIGNAL(readyRead()), this, SLOT(temp()));
}

CESelector_UI::~CESelector_UI()
{
    delete ui;
}

void CESelector_UI::temp()
{

    qDebug() << "temp";
    qDebug() << this->sock->pendingDatagramSize();
}
