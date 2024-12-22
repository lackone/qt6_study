#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto wid = new QWidget();
    wid->setLayout(ui->verticalLayout);
    setCentralWidget(wid);

    auto iplist = getLocalIpAddr();
    for (auto &v : iplist) {
        ui->comboBox->addItem(v);
    }

    ui->spinBox->setRange(1, 99999);
    ui->spinBox->setValue(8888);

    socket = new QTcpSocket();

    connect(socket, SIGNAL(connected()), this, SLOT(connectserver()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnectserver()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(serverreaddata()));
}

MainWindow::~MainWindow() { delete ui; }

QList<QString> MainWindow::getLocalIpAddr()
{
    auto hostname = QHostInfo::localHostName();
    auto hi       = QHostInfo::fromName(hostname);

    auto list = hi.addresses();

    QList<QString> ip;
    if (!list.empty()) {
        for (auto &v : list) {
            if (v.protocol() == QAbstractSocket::IPv4Protocol) {
                ip.append(v.toString());
            }
        }
    }

    return ip;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
    }
    event->accept();
}

void MainWindow::on_connect_btn_clicked()
{
    auto addr = ui->comboBox->currentText();
    auto port = ui->spinBox->value();
    qDebug() << addr << port;
    socket->connectToHost(addr, port);

    //等待，不然无法触发connected()
    if (socket->waitForConnected()) {
        qDebug() << "成功";
    }
}

void MainWindow::on_stop_btn_clicked()
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
    }
}

void MainWindow::on_send_btn_clicked()
{
    auto msg = ui->lineEdit->text();

    ui->plainTextEdit->appendPlainText("[out]" + msg);

    auto data = msg.toUtf8();
    data.append("\n");
    socket->write(data);
}

void MainWindow::connectserver()
{
    ui->plainTextEdit->appendPlainText("连接到服务端");
    ui->plainTextEdit->appendPlainText("peer address:" + socket->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("peer port:" + QString::number(socket->peerPort()));
}

void MainWindow::disconnectserver() { ui->plainTextEdit->appendPlainText("断开连接"); }

void MainWindow::serverreaddata()
{
    while (socket->canReadLine()) {
        ui->plainTextEdit->appendPlainText("[in]" + socket->readLine());
    }
}
