#include "ceselector_ui.h"

CESelector_UI::CESelector_UI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CESelector_UI)
{

    ui->setupUi(this);
    /*
        여기에 connect를 써서 다른 UI를 띄워야 할 듯 함.
        http://stackoverflow.com/questions/5027406/how-to-move-to-another-window-in-qt-by-a-pushbutton
    */
}

CESelector_UI::~CESelector_UI()
{
    delete ui;

}
