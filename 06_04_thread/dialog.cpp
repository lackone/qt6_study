#include "dialog.h"

#include <QHBoxLayout>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    start_btn = new QPushButton("开始");
    stop_btn  = new QPushButton("停止");
    exit_btn  = new QPushButton("退出");

    auto layout = new QHBoxLayout();
    layout->addWidget(start_btn);
    layout->addWidget(stop_btn);
    layout->addWidget(exit_btn);

    connect(start_btn, SIGNAL(clicked()), this, SLOT(startwork()));
    connect(stop_btn, SIGNAL(clicked()), this, SLOT(stopwork()));
    connect(exit_btn, SIGNAL(clicked()), this, SLOT(close()));

    setLayout(layout);
}

Dialog::~Dialog() { delete ui; }

void Dialog::startwork()
{
    for (int i = 0; i < MAX_NUMS; i++) {
        works[i] = new Work();

        works[i]->start();
    }
}

void Dialog::stopwork()
{
    for (int i = 0; i < MAX_NUMS; i++) {
        works[i]->terminate();
        works[i]->wait();
    }
}
