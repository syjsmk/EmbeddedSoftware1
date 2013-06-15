#include "ceselector_ui.h"
#include "ui_ceselector_ui.h"

CESelector_UI::CESelector_UI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CESelector_UI)
{
    ui->setupUi(this);
    // 여기 내부에서 connect 써야 할 것 같음.
    // http://stackoverflow.com/questions/5027406/how-to-move-to-another-window-in-qt-by-a-pushbutton
}

CESelector_UI::~CESelector_UI()
{
    delete ui;
}
