#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //设置窗口位置和大小
    setGeometry(300, 150, 500, 300);

    btn1 = new QPushButton("按钮1", this);
    btn2 = new QPushButton("按钮2", this);

    btn1->setGeometry(20, 20, 100, 30);

    btn2->setGeometry(20, 100, 100, 30);

    //设置槽和信号
    connect(btn1, SIGNAL(clicked()), this, SLOT(btn1_click()));

    connect(btn2, SIGNAL(clicked()), this, SLOT(btn2_click()));
}

MainWindow::~MainWindow() {}

void MainWindow::btn1_click() { setStyleSheet("QMainWindow{background-color:red}"); }

void MainWindow::btn2_click() { setStyleSheet("QMainWindow{background-color:blue}"); }
