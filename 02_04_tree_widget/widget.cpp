#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1、添加一级节点
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0, "hello");
    item->setCheckState(0, Qt::Checked);

    QTreeWidgetItem *item2 = new QTreeWidgetItem(item);
    item2->setText(0, "test");
    item2->setCheckState(0, Qt::Checked);

    QTreeWidgetItem *item3 = new QTreeWidgetItem(item2);
    item3->setText(0, "11111");
    item3->setCheckState(0, Qt::Checked);

    //添加顶层节点
    ui->treeWidget->addTopLevelItem(item);

    //隐藏表头
    ui->treeWidget->setHeaderHidden(true);

    //展开节点
    ui->treeWidget->expandAll();
}

Widget::~Widget() { delete ui; }
