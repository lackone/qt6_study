#include "mainwindow.h"

#include <QHostInfo>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto wid = new QWidget();
    wid->setLayout(ui->verticalLayout);
    setCentralWidget(wid);

    ui->source_spbox->setRange(1, 99999);
    ui->target_spbox->setRange(1, 99999);

    auto iplist = getLocalIpAddr();
    for (auto &v : iplist) {
        ui->comboBox->addItem(v);
    }

    socket = new QUdpSocket();

    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

MainWindow::~MainWindow() { delete ui; }

QList<QString> MainWindow::getLocalIpAddr()
{
    auto hostname = QHostInfo::localHostName();

    auto hi = QHostInfo::fromName(hostname);

    auto list = hi.addresses();

    QList<QString> ip;
    for (auto &v : list) {
        if (v.protocol() == QAbstractSocket::IPv4Protocol) {
            ip.append(v.toString());
        }
    }

    return ip;
}

void MainWindow::on_start_btn_clicked()
{
    auto port = ui->source_spbox->value();

    if (socket->bind(port)) {
        ui->plainTextEdit->appendPlainText("绑定成功");
        ui->plainTextEdit->appendPlainText("port:" + QString::number(port));
    } else {
        ui->plainTextEdit->appendPlainText("绑定失败");
    }
}

void MainWindow::on_stop_btn_clicked()
{
    socket->abort();
    ui->plainTextEdit->appendPlainText("解除绑定");
}

void MainWindow::on_send_btn_clicked()
{
    auto ip   = ui->comboBox->currentText();
    auto port = ui->target_spbox->value();
    auto msg  = ui->lineEdit->text();

    QHostAddress addr(ip);

    QByteArray buf = msg.toUtf8();
    socket->writeDatagram(buf, addr, port);  //发送数据

    ui->plainTextEdit->appendPlainText("[out]" + msg);
}

void MainWindow::on_broadcast_btn_clicked()
{
    auto port = ui->target_spbox->value();
    auto msg  = ui->lineEdit->text();

    QByteArray buf = msg.toUtf8();
    socket->writeDatagram(buf, QHostAddress::Broadcast, port);  //发送数据

    ui->plainTextEdit->appendPlainText("[broadcast]" + msg);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    socket->abort();
    ui->plainTextEdit->appendPlainText("解除绑定");

    event->accept();
}

//读取数据
void MainWindow::readData()
{
    //此函数返回真，至少有一个数据报需要读取
    while (socket->hasPendingDatagrams()) {
        QByteArray buf;
        buf.resize(socket->pendingDatagramSize());

        QHostAddress addr;
        quint16      port;

        socket->readDatagram(buf.data(), buf.size(), &addr, &port);

        QString str(buf.data());

        ui->plainTextEdit->appendPlainText("[From:" + addr.toString() + ":" + QString::number(port) + "]" + str);
    }
}
