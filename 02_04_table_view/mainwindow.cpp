#include "mainwindow.h"

#include <QStandardItemModel>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTableView();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::initTableView()
{
    // 1、添加表头
    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem("学号"));
    model->setHorizontalHeaderItem(1, new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(2, new QStandardItem("性别"));
    model->setHorizontalHeaderItem(3, new QStandardItem("分数"));

    ui->tableView->setColumnWidth(0, 120);

    // 2、添加数据
    model->setItem(0, 0, new QStandardItem("001"));
    model->setItem(0, 1, new QStandardItem("小张"));
    model->setItem(0, 2, new QStandardItem("男"));
    model->setItem(0, 3, new QStandardItem("123"));

    model->setItem(1, 0, new QStandardItem("002"));
    model->setItem(1, 1, new QStandardItem("小红"));
    model->setItem(1, 2, new QStandardItem("男"));
    model->setItem(1, 3, new QStandardItem("234"));

    model->setItem(2, 0, new QStandardItem("003"));
    model->setItem(2, 1, new QStandardItem("小明"));
    model->setItem(2, 2, new QStandardItem("男"));
    model->setItem(2, 3, new QStandardItem("53"));

    //不可编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView->setSortingEnabled(true);

    //排序
    model->sort(3, Qt::DescendingOrder);

    // ui->tableView->sortByColumn(3, Qt::DescendingOrder);

    ui->tableView->setModel(model);
}
