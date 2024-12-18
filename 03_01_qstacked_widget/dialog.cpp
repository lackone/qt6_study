#include "dialog.h"

#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("stacked widget");

    QHBoxLayout *layout = new QHBoxLayout();

    list = new QListWidget();
    list->addItem("11111");
    list->addItem("22222");
    list->addItem("33333");

    label1 = new QLabel("111111");
    label2 = new QLabel("222222");
    label3 = new QLabel("333333");

    stack = new QStackedWidget();
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    layout->addWidget(list);
    layout->addWidget(stack);
    layout->setStretchFactor(list, 1);
    layout->setStretchFactor(stack, 5);

    // connect(list, SIGNAL(clicked(QModelIndex)), this, SLOT(listclick(QModelIndex)));

    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));

    setLayout(layout);
}

Dialog::~Dialog() {}

void Dialog::listclick(QModelIndex index)
{
    qDebug() << index.row();

    stack->setCurrentIndex(index.row());
}
