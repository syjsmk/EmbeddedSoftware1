#ifndef COOLER_UI_H
#define COOLER_UI_H

#include <QtGui/QMainWindow>

namespace Ui {
    class Cooler_UI;
}

class Cooler_UI : public QMainWindow {
    Q_OBJECT
public:
    Cooler_UI(QWidget *parent = 0);
    ~Cooler_UI();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Cooler_UI *m_ui;

private slots:
    void on_tempDownButton_clicked();
    void on_tempUpButton_clicked();
    void on_powerButton_clicked();
};

#endif // COOLER_UI_H
