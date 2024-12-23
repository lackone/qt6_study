#ifndef HANDLETHREAD_H
#define HANDLETHREAD_H

#include <QByteArray>  //字节数组
#include <QTcpSocket>  //TCP连接
#include <QThread>     //线程
#include <QtNetwork>   //TCP/IP客户端和服务器的类

class HandleThread : public QThread
{
    Q_OBJECT
public:
    HandleThread(int sid, QObject *parent = nullptr);

signals:
    void error(QTcpSocket::SocketError err);

protected:
    void run();

private:
    int sid;
};

#endif  // HANDLETHREAD_H
