#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString qss = "color:#becec6;";
    this->setStyleSheet(qss);

    ui->widget_1->settext("主页");
    ui->widget_1->setimage(":/images/v-home.png");

    ui->widget_2->settext("通讯录");
    ui->widget_2->setimage(":/images/v-contact.png");

    ui->widget_3->settext("相册");
    ui->widget_3->setimage(":/images/v-img.png");

    ui->widget_4->settext("录音");
    ui->widget_4->setimage(":/images/v-record.png");

    update();
}

MainWindow::~MainWindow() { delete ui; }
