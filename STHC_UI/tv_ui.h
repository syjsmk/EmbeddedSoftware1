#ifndef TV_UI_H
#define TV_UI_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class TV_UI;
}

class TV_UI : public QMainWindow
{
    Q_OBJECT

public:
    TV_UI(QWidget *parent = 0);
    ~TV_UI();

private:
    Ui::TV_UI *ui;
};

#endif // TV_UI_H
