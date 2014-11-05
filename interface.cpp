#include "interface.h"
#include "ui_interface.h"
#include <fstream>
#include <iostream>
#include <string>

//minDistance(int pop, int gen, float mut, float elit)

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
//    mind(new minDistance(this))
{
    ui->setupUi(this);
//    setCentralWidget(ui->Layout);
    this->setWindowState(this->windowState() ^ Qt::WindowMaximized);
//    ui->graphInterface->addGraph();
//    ui->graphInterface->addGraph();
//    ui->graphInterface->xAxis->setAutoTickStep(false);
//    ui->graphInterface->yAxis->setAutoTickStep(false);
//    ui->graphInterface->xAxis->setTickStep(0.5);
//    ui->graphInterface->yAxis->setTickStep(0.5);
//    ui->graphInterface->xAxis->setLabel("Latitude");
//    ui->graphInterface->yAxis->setLabel("Longitude");
//    ui->graphInterface->xAxis->setRange(29, 31);
//    ui->graphInterface->yAxis->setRange(55, 59);
}

Interface::~Interface()
{
    delete ui;
//    delete mind;
}

void Interface::on_button_start_clicked()
{
    mind = new minDistance(this,std::stoi(ui->text_pop->text().toStdString()),
                           std::stoi(ui->text_generation->text().toStdString()),
                           std::stof(ui->text_mutation->text().toStdString()),
                           std::stof(ui->text_elitism->text().toStdString()),
                           std::stof(ui->text_crossRate->text().toStdString()));
}
