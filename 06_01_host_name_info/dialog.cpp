#include "dialog.h"

#include <QMessageBox>

#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setLayout(ui->gridLayout);
}

Dialog::~Dialog() { delete ui; }

void Dialog::on_pushButton_clicked()
{
    //获取主机名称
    auto hostname = QHostInfo::localHostName();

    qDebug() << hostname;

    //获取IP
    auto hi2  = QHostInfo::fromName(hostname);
    auto list = hi2.addresses();

    qDebug() << list;

    QString ip;
    if (!list.empty()) {
        for (auto& v : list) {
            if (v.protocol() == QAbstractSocket::IPv4Protocol) {
                ip = v.toString();
                break;
            }
        }
    }

    ui->lineEdit->setText(hostname);
    ui->lineEdit_2->setText(ip);
}

void Dialog::on_pushButton_2_clicked()
{
    QString info;

    //获取所有网络接口
    auto list = QNetworkInterface::allInterfaces();

    for (auto& v : list) {
        info += "设备名称：" + v.name() + "\n";
        info += "硬件地址：" + v.hardwareAddress() + "\n";

        auto entrys = v.addressEntries();
        for (auto& vv : entrys) {
            info += "IP：" + vv.ip().toString() + "\n";
            info += "子网掩码：" + vv.netmask().toString() + "\n";
            info += "广播地址：" + vv.broadcast().toString() + "\n";
        }

        info += "----------------------------------------\n";
    }

    QMessageBox::information(this, "所有信息", info, QMessageBox::Yes);
}
