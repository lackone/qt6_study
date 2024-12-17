#include "mainwindow.h"

#include <QComboBox>
#include <QDockWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPalette>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto *dock1 = new QDockWidget("停靠窗口", this);

    auto pte = dock1->palette();
    pte.setColor(QPalette::Window, Qt::cyan);
    dock1->setAutoFillBackground(true);
    dock1->setPalette(pte);

    auto *label = new QLabel("学历");
    auto *cbox  = new QComboBox();
    cbox->addItem("111");
    cbox->addItem("222");
    cbox->addItem("333");
    cbox->addItem("444");
    auto *layout = new QGridLayout();
    layout->addWidget(label, 0, 0);
    layout->addWidget(cbox, 0, 1);

    layout->setHorizontalSpacing(10);
    layout->setVerticalSpacing(10);

    QWidget *wid = new QWidget();
    wid->setLayout(layout);

    dock1->setWidget(wid);

    dock1->setMaximumSize(300, 300);
}

MainWindow::~MainWindow() { delete ui; }
