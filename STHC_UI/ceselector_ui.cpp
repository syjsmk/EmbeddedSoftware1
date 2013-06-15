#include "ceselector_ui.h"
#include "ui_ceselector_ui.h"

CESelector_UI::CESelector_UI(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::CESelector_UI)
{
    m_ui->setupUi(this);
}

CESelector_UI::~CESelector_UI()
{
    delete m_ui;
}

void CESelector_UI::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
