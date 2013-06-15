#ifndef HEATER_UI_H
#define HEATER_UI_H

#include <QtGui/QMainWindow>

namespace Ui {
    class Heater_UI;
}

class Heater_UI : public QMainWindow {
    Q_OBJECT
public:
    Heater_UI(QWidget *parent = 0);
    ~Heater_UI();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Heater_UI *m_ui;

private slots:
    void on_powerButton_clicked();
    void on_tempDownButton_clicked();
    void on_tempUpButton_clicked();
    void on_windDownButton_clicked();
    void on_windUpButton_clicked();
};

#endif // HEATER_UI_H
