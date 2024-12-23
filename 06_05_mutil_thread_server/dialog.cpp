#include "dialog.h"

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setLayout(ui->verticalLayout);

    cnt = 0;

    server = new ClientServer(this);
    if (!server->listen()) {
        close();
        return;
    }

    ui->lineEdit->setText(tr("%1").arg(server->serverPort()));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog::~Dialog() { delete ui; }

void Dialog::handleCnt() { ui->lineEdit_2->setText(tr("客户端请求%1次").arg(++cnt)); }
