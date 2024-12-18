#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initTreeView();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::initTreeView()
{
    //构造model
    itemModel = new QStandardItemModel(ui->treeView);

    itemModel->setHorizontalHeaderLabels(QStringList() << "编号"
                                                       << "性别"
                                                       << "年龄");

    //创建一级节点
    QList<QStandardItem *> item1;
    QStandardItem *        item11 = new QStandardItem("001");
    QStandardItem *        item22 = new QStandardItem("男");
    QStandardItem *        item33 = new QStandardItem("22");
    item1.append(item11);
    item1.append(item22);
    item1.append(item33);
    itemModel->appendRow(item1);

    //创建二级节点
    QList<QStandardItem *> item_sub_1;
    QStandardItem *        item_sub_11 = new QStandardItem("003");
    QStandardItem *        item_sub_22 = new QStandardItem("男");
    QStandardItem *        item_sub_33 = new QStandardItem("33");
    item_sub_1.append(item_sub_11);
    item_sub_1.append(item_sub_22);
    item_sub_1.append(item_sub_33);
    item11->appendRow(item_sub_1);

    //创建三级节点
    QList<QStandardItem *> item_sub_sub_1;
    QStandardItem *        item_sub_sub_11 = new QStandardItem("004");
    QStandardItem *        item_sub_sub_22 = new QStandardItem("男");
    QStandardItem *        item_sub_sub_33 = new QStandardItem("44");
    item_sub_sub_1.append(item_sub_sub_11);
    item_sub_sub_1.append(item_sub_sub_22);
    item_sub_sub_1.append(item_sub_sub_33);
    item_sub_11->appendRow(item_sub_sub_1);

    QList<QStandardItem *> item2;
    QStandardItem *        item44 = new QStandardItem("002");
    QStandardItem *        item55 = new QStandardItem("女");
    QStandardItem *        item66 = new QStandardItem("22");
    item2.append(item44);
    item2.append(item55);
    item2.append(item66);
    itemModel->appendRow(item2);

    ui->treeView->setModel(itemModel);
}
