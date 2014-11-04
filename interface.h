#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include "mindistance.h"

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

private slots:
    void on_button_start_clicked();

private:
    Ui::Interface *ui;
    minDistance *mind;
};

#endif // INTERFACE_H
