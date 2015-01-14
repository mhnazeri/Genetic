#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <vector>
#include "qcustomplot.h"
#include "mindistance.h"
#include "sphere.h"
#include "banchmark1.h"

namespace Ui {
class Interface;
}

class minDistance;
class Sphere;
class banchmark1;
class Interface : public QMainWindow
{
    Q_OBJECT
    friend class minDistance;
    friend class Sphere;
    friend class banchmark1;
//    friend class nqueens;

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();
    void Plot(std::vector<double> &x, std::vector<double> &y, QColor color, QCPScatterStyle::ScatterShape shape, QCPGraph::LineStyle line, float xStep, float yStep, QString xLabel, QString ylabel, int xRange1, int xRange2, int yRange1, int yRange2, int size);
    void ClearGraph();

private slots:
    void on_button_start_clicked();

    void on_button_reset_clicked();

    void on_button_stop_clicked();

private:
    Ui::Interface *ui;
    minDistance *mind;
    Sphere *sphere;
    banchmark1 *g1;
    enum{
        FIRE_STATION, SPHERE, NQUEENS, G1
    };
};

#endif // INTERFACE_H
