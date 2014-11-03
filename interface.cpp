#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface),
    mind(new minDistance(this))
{
    ui->setupUi(this);
//    mind = new minDistance(this);

}

Interface::~Interface()
{
    delete ui;
}
