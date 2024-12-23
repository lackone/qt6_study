#include "clientserver.h"

ClientServer::ClientServer(QObject *parent) : QTcpServer{parent} { dlg = (Dialog *)parent; }

void ClientServer::incomingConnection(qintptr sid)
{
    HandleThread *thread = new HandleThread(sid);

    //此处用于处理对话框显示统计访问次数信息
    connect(thread, SIGNAL(finished()), dlg, SLOT(handleCnt()));

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()), Qt::DirectConnection);

    thread->start();
}
