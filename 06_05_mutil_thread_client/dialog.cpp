#include "dialog.h"

#include <QMessageBox>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setLayout(ui->verticalLayout);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(runexec()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(close()));

    socket = new QTcpSocket();
    connect(socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(handleError(QAbstractSocket::SocketError)));
}

Dialog::~Dialog() { delete ui; }

void Dialog::on_pushButton_clicked() {}

void Dialog::handleError(QAbstractSocket::SocketError err)
{
    switch (err) {
        case QAbstractSocket::RemoteHostClosedError:  //远程主机关闭连接
            QMessageBox::information(this, "提示", "远程主机关闭连接");
            break;
        case QAbstractSocket::HostNotFoundError:  //找不到主机
            QMessageBox::information(this, "提示", "找不到主机");
            break;
        case QAbstractSocket::ConnectionRefusedError:  //连接被拒绝
            QMessageBox::information(this, "提示", "连接被拒绝");
            break;
        default:
            QMessageBox::information(this, "提示", socket->errorString());
            break;
    }
}

void Dialog::runexec()
{
    socket->abort();

    socket->connectToHost(ui->lineEdit->text(), ui->lineEdit_2->text().toInt());
}
