#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new QWebSocketServer(QStringLiteral("test"), QWebSocketServer::NonSecureMode, this);

    connect(server, SIGNAL(newConnection()), this, SLOT(getnewConnect()));

    server->listen(QHostAddress::Any, 8899);
};
Widget::~Widget()
{
    delete ui;

    for (auto &v : socket_list) {
        v->close();
    }

    server->close();
}

//获取新连接
void Widget::getnewConnect()
{
    if (server->hasPendingConnections()) {
        auto socket = server->nextPendingConnection();

        ui->content_pedit->appendPlainText(socket->origin() + "客户端连接到服务器");

        socket_list << socket;

        auto item = new QListWidgetItem();
        item->setText(socket->origin());
        ui->listWidget->addItem(item);  //将客户端添加到用户列表

        //连接断开
        connect(socket, &QWebSocket::disconnected, this, [socket, this] {
            ui->content_pedit->appendPlainText(socket->origin() + "客户端已经断开服务器");
            socket_list.removeOne(socket);
            for (int i = 0; i < ui->listWidget->count(); i++) {
                auto v = ui->listWidget->item(i);
                if (v->text() == socket->origin()) {
                    ui->listWidget->removeItemWidget(v);
                    delete v;
                    break;
                }
            }
            socket->deleteLater();
        });

        //接收消息
        connect(socket, SIGNAL(textMessageReceived(QString)), this, SLOT(msgReceived(QString)));
        //错误
        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onerrorFunc(QAbstractSocket::SocketError)));
    }
}

void Widget::msgReceived(QString msg)
{
    QJsonDocument json = QJsonDocument::fromJson(msg.toLatin1().data());

    if (json.isNull()) {
        auto socket = qobject_cast<QWebSocket *>(sender());
        ui->content_pedit->appendPlainText("收到客户端消息[" + socket->origin() + "]:" + msg);
    } else {
        QJsonObject obj = json.object();
        QString     dst = obj["dst"].toString();
        for (auto &v : socket_list) {
            if (dst == v->origin()) {
                v->sendTextMessage(msg);
            }
        }
    }
}

//错误处理
void Widget::onerrorFunc(QAbstractSocket::SocketError err)
{
    auto socket = qobject_cast<QWebSocket *>(sender());

    ui->content_pedit->appendPlainText(socket->origin() + "出错" + socket->errorString());
}

void Widget::on_send_btn_clicked()
{
    auto msg = ui->msg_edit->toPlainText().trimmed();
    if (msg.isEmpty()) {
        return;
    }

    if (ui->radioButton->isChecked())  //群发
    {
        if (socket_list.size() == 0) {
            return;
        }
        for (auto &v : socket_list) {
            v->sendTextMessage(msg);
        }

        ui->content_pedit->appendPlainText("服务器给所有发送:" + msg);

    } else  //单发
    {
        if (!ui->listWidget->currentItem()) {
            return;
        }

        auto curr = ui->listWidget->currentItem()->text();
        for (auto &v : socket_list) {
            if (v->origin() == curr) {
                v->sendTextMessage(msg);
                ui->content_pedit->appendPlainText("服务器给[" + v->origin() + "]发送消息:" + msg);
                break;
            }
        }
    }
}
