#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow   w;

    w.resize(500, 300);  //设置窗口大小
    w.setWindowTitle("QT第一个程序设计");

    w.show();
    return a.exec();
}
