#include "hmmanager.h"
#include "ui_hmmanager.h"

HMManager::HMManager(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::HMManager)
{
    ui->setupUi(this);
}

HMManager::~HMManager()
{
    delete ui;
}
