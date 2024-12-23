#ifndef MYHTTPSERVER_H
#define MYHTTPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyHttpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyHttpServer(QObject *parent = nullptr);
    ~MyHttpServer();

private slots:
    void newConnection();

public:
    QTcpSocket *socket;
    QTcpServer *server;
};

#endif  // MYHTTPSERVER_H
