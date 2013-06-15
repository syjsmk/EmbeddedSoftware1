#ifndef LIGHT_UI_H
#define LIGHT_UI_H

#include <QtGui/QMainWindow>

namespace Ui {
    class Light_UI;
}

class Light_UI : public QMainWindow {
    Q_OBJECT
public:
    Light_UI(QWidget *parent = 0);
    ~Light_UI();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Light_UI *m_ui;
};

#endif // LIGHT_UI_H
