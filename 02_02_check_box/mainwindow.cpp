#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setGeometry(300, 300, 400, 300);

    setStyleSheet("QMainWindow{background-color:red;}");

    chk = new QCheckBox(this);
    chk->setGeometry(30, 30, 100, 30);
    chk->setText("选项");
    chk->setCheckState(Qt::Checked);  //选中

    chk->setTristate();  //开启三态

    connect(chk, SIGNAL(stateChanged(int)), this, SLOT(checkboxState(int)));
}

MainWindow::~MainWindow() {}

void MainWindow::checkboxState(int state)
{
    switch (state) {
        case Qt::Checked:  //选中
            chk->setText("选中");
            break;
        case Qt::Unchecked:  //未选中
            chk->setText("未选中");
            break;
        case Qt::PartiallyChecked:  //半选中
            chk->setText("半选中");
            break;
        default:
            break;
    }
}
