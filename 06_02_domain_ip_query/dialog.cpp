#include "dialog.h"

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setLayout(ui->gridLayout);
}

Dialog::~Dialog() { delete ui; }

//网络层协议
QString Dialog::protocolTypeName(QAbstractSocket::NetworkLayerProtocol pro)
{
    switch (pro) {
        case QAbstractSocket::IPv4Protocol:
            return "ipv4";
            break;
        case QAbstractSocket::IPv6Protocol:
            return "ipv6";
            break;
        case QAbstractSocket::AnyIPProtocol:
            return "any";
            break;
        case QAbstractSocket::UnknownNetworkLayerProtocol:
            return "unknown";
            break;
        default:
            return "";
            break;
    }
}

void Dialog::lookupHostInfo(const QHostInfo &info)
{
    auto list = info.addresses();
    for (auto &v : list) {
        ui->plainTextEdit->appendPlainText("类型：" + protocolTypeName(v.protocol()));
        ui->plainTextEdit->appendPlainText("IP：" + v.toString());
    }
}

void Dialog::on_pushButton_clicked()
{
    auto name = ui->lineEdit->text();
    ui->plainTextEdit->appendPlainText("主机：" + name);
    QHostInfo::lookupHost(name, this, SLOT(lookupHostInfo(QHostInfo)));
}

void Dialog::on_pushButton_2_clicked() { ui->plainTextEdit->clear(); }
