#include "ceselector_ui.h"
#include "ui_ceselector_ui.h"

CESelector_UI::CESelector_UI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CESelector_UI)
{
    ui->setupUi(this);
}

CESelector_UI::~CESelector_UI()
{
    delete ui;
}

void CESelector_UI::setUiList(QList<CE*> *list)
{
    this->ceList = list;
}

void CESelector_UI::on_pushButton_clicked()
{
    qDebug() << "pushButton";
    CE* ce;
    foreach(ce, *ceList)
    {
        //qDebug() << ce->ui->show();
        qDebug() << ceList->size();
        ce->ui->show();
    }
}
