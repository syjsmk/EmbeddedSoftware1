#include "tv_ui.h"
#include "ui_tv_ui.h"

TV_UI::TV_UI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TV_UI)
{
    ui->setupUi(this);
}

TV_UI::~TV_UI()
{
    delete ui;
}
