#include "mainwindow.h"

#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QTextEdit *medit = new QTextEdit();
    setCentralWidget(medit);  //设置为中央窗体

    // 创建
    QDockWidget *dock1 = new QDockWidget("111", this);
    // 设置特性
    dock1->setFeatures(QDockWidget::DockWidgetMovable);
    // 停靠区域
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock1->setWindowTitle("停靠1");
    QTextEdit *edit1 = new QTextEdit();
    edit1->setText("11111111111111111");
    dock1->setWidget(edit1);
    addDockWidget(Qt::RightDockWidgetArea, dock1);

    QDockWidget *dock2 = new QDockWidget("222", this);
    dock2->setWindowTitle("停靠2");
    QTextEdit *edit2 = new QTextEdit();
    edit2->setText("2222222222222222222");
    dock2->setWidget(edit2);
    addDockWidget(Qt::RightDockWidgetArea, dock2);
}

MainWindow::~MainWindow() {}
