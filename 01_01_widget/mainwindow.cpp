#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //创建标签
    label = new QLabel("我是一个标签", this);
    //设置大小
    label->setGeometry(10, 10, 200, 200);
    //移动位置
    label->move(50, 50);
    //设置样式
    label->setStyleSheet("QLabel{background-color:black;color:red}");
    //设置字体
    label->setFont(QFont("幼圆", 16));
}

MainWindow::~MainWindow() {}
