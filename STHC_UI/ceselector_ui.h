#ifndef CESELECTOR_UI_H
#define CESELECTOR_UI_H

#include <QtGui/QMainWindow>

namespace Ui {
    class CESelector_UI;
}

class CESelector_UI : public QMainWindow {
    Q_OBJECT
public:
    CESelector_UI(QWidget *parent = 0);
    ~CESelector_UI();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CESelector_UI *m_ui;
};

#endif // CESELECTOR_UI_H
