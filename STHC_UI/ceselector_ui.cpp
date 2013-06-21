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
