#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QListWidgetItem *item = new QListWidgetItem("4444444");
    ui->listWidget->addItem(item);

    item->setTextAlignment(Qt::AlignCenter);

    QStringList slist;
    slist << "新年好"
          << "11111"
          << "2222222222"
          << "3333333";

    ui->listWidget->addItems(slist);
}

Widget::~Widget() { delete ui; }
