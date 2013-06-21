#include "tv_ui.h"
#include "ui_tv_ui.h"

TV_UI::TV_UI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TV_UI)
{
    ui->setupUi(this);
    this->netMgr = new netManager();
    netMgr->broadcast();

}

TV_UI::~TV_UI()
{
    delete ui;

}

void TV_UI::on_powerButton_clicked()
{

}

void TV_UI::on_chUpButton_clicked()
{

}

void TV_UI::on_chDownButton_clicked()
{

}

void TV_UI::on_volUpButton_clicked()
{

}

void TV_UI::on_volDownButton_clicked()
{

}
