#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // 1、拆分窗口

    auto split = new QSplitter(Qt::Horizontal);

    auto txtedit = new QTextEdit("左边", split);

    // 2、右边拆分
    auto rsplit = new QSplitter(Qt::Vertical, split);

    auto rtxtedit1 = new QTextEdit("111", rsplit);
    auto rtxtedit2 = new QTextEdit("222", rsplit);

    auto sptest    = new QSplitter(Qt::Vertical, rsplit);
    auto rtxtedit3 = new QTextEdit("333", sptest);

    auto sptest2   = new QSplitter(Qt::Horizontal, rsplit);
    auto rtxtedit4 = new QTextEdit("444", sptest2);
    auto rtxtedit5 = new QTextEdit("555", sptest2);

    auto rtxtedit6 = new QTextEdit("666", split);

    split->show();
}

MainWindow::~MainWindow() {}
