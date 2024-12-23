#include "handlethread.h"

HandleThread::HandleThread(int sid, QObject *parent) : QThread(parent), sid(sid) {}

//通过start()调用run()执行
void HandleThread::run()
{
    QTcpSocket socket;

    if (!socket.setSocketDescriptor(sid)) {
        //触发信号
        emit error(socket.error());
        return;
    }

    QByteArray  buf;
    QDataStream out(&buf, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_6_8);

    socket.write(buf);
    socket.disconnectFromHost();
}
