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

    server = new QTcpServer();

    //新连接
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_start_btn_clicked()
{
    auto ip   = ui->comboBox->currentText();
    auto port = ui->spinBox->value();

    QHostAddress addr(ip);
    server->listen(addr, port);

    ui->plainTextEdit->appendPlainText("开始监听");
    ui->plainTextEdit->appendPlainText("服务器地址：" + server->serverAddress().toString());
    ui->plainTextEdit->appendPlainText("服务器端口：" + QString::number(server->serverPort()));
}

void MainWindow::on_stop_btn_clicked()
{
    if (server->isListening()) {
        ui->plainTextEdit->appendPlainText("关闭");
        server->close();
    }
}

void MainWindow::on_send_btn_clicked()
{
    auto msg = ui->lineEdit->text();

    ui->plainTextEdit->appendPlainText("[out]" + msg);

    auto data = msg.toUtf8();
    data.append("\n");

    qDebug() << "发送数据";
    qDebug() << socket->write(data);
}

void MainWindow::newConnection()
{
    socket = server->nextPendingConnection();

    //
    connect(socket, SIGNAL(connected()), this, SLOT(clientConnect()));  //连接

    connect(socket, SIGNAL(disconnected()), this, SLOT(clientdisconnect()));  //断开连接

    connect(socket, SIGNAL(readyRead()), this, SLOT(clientreaddata()));  //读取数据

    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(clientstatechange(QAbstractSocket::SocketState)));  //状态改变
}

void MainWindow::clientConnect()
{
    qDebug() << "客户连接";
    //客户端连接
    ui->plainTextEdit->appendPlainText("客户端socket连接");
    ui->plainTextEdit->appendPlainText("peer address:" + socket->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("端口:" + QString::number(socket->peerPort()));
}

void MainWindow::clientdisconnect()
{
    ui->plainTextEdit->appendPlainText("客户端socket断开连接");

    socket->deleteLater();
}

void MainWindow::clientreaddata()
{
    qDebug() << "读取数据";
    while (socket->canReadLine()) {
        ui->plainTextEdit->appendPlainText("[in]" + socket->readLine());
    }
}

void MainWindow::clientstatechange(QAbstractSocket::SocketState state)
{
    QString str;
    switch (state) {
        case QAbstractSocket::UnconnectedState:
            str = "Unconnected";
            break;
        case QAbstractSocket::HostLookupState:
            str = "HostLookup";
            break;
        case QAbstractSocket::ConnectingState:
            str = "Connecting";
            break;
        case QAbstractSocket::ConnectedState:
            str = "Connected";
            break;
        case QAbstractSocket::BoundState:
            str = "Bound";
            break;
        case QAbstractSocket::ListeningState:
            str = "Listening";
            break;
        case QAbstractSocket::ClosingState:
            str = "Closing";
            break;
        default:
            break;
    }

    ui->plainTextEdit->appendPlainText("客户端状态：" + str);
}

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
    //判断服务是否监听
    if (server->isListening()) {
        server->close();
    }

    event->accept();
}
