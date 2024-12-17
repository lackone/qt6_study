#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setGeometry(300, 300, 400, 300);

    radio1 = new QRadioButton("男", this);
    radio2 = new QRadioButton("女", this);

    radio1->setGeometry(10, 10, 200, 30);
    radio2->setGeometry(10, 50, 200, 30);

    radio1->setChecked(true);
    radio2->setChecked(false);
}

MainWindow::~MainWindow() {}
