#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setGeometry(300, 300, 400, 300);

    btnbox = new QDialogButtonBox(this);
    btnbox->setGeometry(30, 30, 200, 30);

    btnbox->addButton(QDialogButtonBox::Cancel);
    btnbox->button(QDialogButtonBox::Cancel)->setText("取消");

    btn = new QPushButton("自定义", this);
    btnbox->addButton(btn, QDialogButtonBox::ActionRole);

    connect(btnbox, SIGNAL(clicked(QAbstractButton *)), this, SLOT(btnclick(QAbstractButton *)));
}

MainWindow::~MainWindow() {}

void MainWindow::btnclick(QAbstractButton *bb)
{
    if (bb == btnbox->button(QDialogButtonBox::Cancel)) {
        qDebug() << "cancel click";
    } else if (bb == btn) {
        qDebug() << "btn click";
    }
}
