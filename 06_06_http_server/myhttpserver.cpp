#include "myhttpserver.h"

MyHttpServer::MyHttpServer(QObject *parent) : QObject{parent}
{
    server = new QTcpServer();

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if (!server->listen(QHostAddress::Any, 8080)) {
        qDebug() << "启动失败";
    } else {
        qDebug() << "启动成功";
    }
}

void MyHttpServer::newConnection()
{
    socket = server->nextPendingConnection();

    while (!(socket->waitForReadyRead(100)))
        ;

    char data[1000];
    socket->read(data, 1000);
    qDebug() << "获取数据《《《《《" << QString(data);

    socket->write("HTTP/1.1 200 OK\r\n");
    socket->write("Content-Type:text/html\r\n");
    socket->write("Connection:close\r\n");
    socket->write("Refresh:1\r\n\r\n");

    static int cnt = 0;

    socket->write("<!doctype><meta charset=\"utf-8\"><html><header>httpserver</header><body>hello，连接到服务器秒数:");
    socket->write(QString::number(cnt++).toUtf8());
    socket->write("</body></html>");

    socket->flush();

    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));

    socket->disconnectFromHost();
}

MyHttpServer::~MyHttpServer() { socket->close(); }
