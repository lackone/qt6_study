#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置行和列
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(5);

    QStringList slist;
    slist << "学号"
          << "分数"
          << "性别"
          << "年龄"
          << "地址";
    ui->tableWidget->setHorizontalHeaderLabels(slist);

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("001"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("99"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("男"));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem("22"));
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem("中国"));
}

Widget::~Widget() { delete ui; }
