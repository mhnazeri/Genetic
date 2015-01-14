#include "interface.h"
//#include "ui_interface.h"
#include <fstream>
#include <iostream>
#include <string>

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);
    this->setWindowState(this->windowState() ^ Qt::WindowMaximized);
}

Interface::~Interface()
{
//    delete mind;
    delete ui;
}

void Interface::on_button_start_clicked()
{
    QString algo = "";
    algo = ui->box_algorithm->currentText();
    switch(algo)
    {
    case "Fire Staion":
        mind = new minDistance(this,std::stoi(ui->text_pop->text().toStdString()),
                               std::stoi(ui->text_generation->text().toStdString()),
                               std::stof(ui->text_mutation->text().toStdString()),
                               std::stof(ui->text_elitism->text().toStdString()),
                               std::stof(ui->text_crossRate->text().toStdString()));
        mind->Run();
        break;
    case "Sphere":
        sphere = new Sphere(this,std::stoi(ui->text_pop->text().toStdString()),
                               std::stoi(ui->text_generation->text().toStdString()),
                               std::stof(ui->text_mutation->text().toStdString()),
                               std::stof(ui->text_elitism->text().toStdString()),
                               std::stof(ui->text_crossRate->text().toStdString()));
        break;
    case "NQueens":
        break;
    }


}

void Interface::Plot(std::vector<double> &x, std::vector<double> &y, QColor color, QCPScatterStyle::ScatterShape shape,
                     QCPGraph::LineStyle line, float xStep, float yStep, QString xLabel, QString ylabel, int xRange1,
                     int xRange2, int yRange1, int yRange2, int size)
{
    QVector<double> lat = QVector<double>::fromStdVector(y);
    QVector<double> lon = QVector<double>::fromStdVector(x);
    ui->graphInterface->addGraph();
    ui->graphInterface->xAxis->setAutoTickStep(false);
    ui->graphInterface->yAxis->setAutoTickStep(false);
    ui->graphInterface->xAxis->setTickStep(xStep);
    ui->graphInterface->yAxis->setTickStep(yStep);
    ui->graphInterface->xAxis->setLabel(xLabel);
    ui->graphInterface->yAxis->setLabel(ylabel);
    ui->graphInterface->xAxis->setRange(xRange1, xRange2);
    ui->graphInterface->yAxis->setRange(yRange1, yRange2);
    int num_graph = ui->graphInterface->graphCount();
    const int graph_pos = num_graph - 1;
    ui->graphInterface->graph(graph_pos)->setData(lon, lat);
    ui->graphInterface->graph(graph_pos)->setScatterStyle(QCPScatterStyle(shape, color, Qt::white, size));
    ui->graphInterface->graph(graph_pos)->setLineStyle(line);
    ui->graphInterface->replot();
}

void Interface::on_button_reset_clicked()
{
    ui->text_answer->setText("");
    ui->text_crossRate->setText("");
    ui->text_elitism->setText("");
    ui->text_generation->setText("");
    ui->text_mutation->setText("");
    ui->text_pop->setText("");
    ui->graphInterface->clearGraphs();
    ui->graphInterface->replot();
}

void Interface::ClearGraph()
{
    ui->graphInterface->clearGraphs();
}

void Interface::on_button_stop_clicked()
{
    delete mind;
    exit(0);
}
