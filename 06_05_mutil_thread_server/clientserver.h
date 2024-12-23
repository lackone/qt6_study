#ifndef CLIENTSERVER_H
#define CLIENTSERVER_H

#include <QTcpServer>
class Dialog;

#include "dialog.h"
#include "handlethread.h"

class ClientServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ClientServer(QObject *parent = nullptr);

protected:
    //当有新连接的时候，会自动调用此函数
    void incomingConnection(qintptr sid);

    Dialog *dlg;
};

#endif  // CLIENTSERVER_H
