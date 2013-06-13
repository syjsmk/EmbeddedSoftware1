#ifndef HMMANAGER_H
#define HMMANAGER_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class HMManager;
}

class HMManager : public QMainWindow
{
    Q_OBJECT

public:
    HMManager(QWidget *parent = 0);
    ~HMManager();

private:
    Ui::HMManager *ui;
};

#endif // HMMANAGER_H
