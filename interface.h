#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include "mindistance.h"
#include <vector>
#include "qcustomplot.h"

namespace Ui {
class Interface;
}

class minDistance;
class Interface : public QMainWindow
{
    Q_OBJECT
    friend class minDistance;

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();
    void Plot(std::vector<double> &longi, std::vector<double> &lati, QColor color, QCPScatterStyle::ScatterShape shape, QCPGraph::LineStyle line, float xStep, float yStep, QString xLabel, QString ylabel, int xRange1, int xRange2, int yRange1, int yRange2, int size);

private slots:
    void on_button_start_clicked();

    void on_button_reset_clicked();

    void on_button_stop_clicked();

private:
    Ui::Interface *ui;
    minDistance *mind;
};

#endif // INTERFACE_H
