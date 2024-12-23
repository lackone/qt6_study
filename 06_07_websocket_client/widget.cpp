#include "widget.h"

#include <QJsonDocument>
#include <QJsonObject>

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = nullptr;

    ui->url_edit->setText("ws://127.0.0.1:8899");
}

Widget::~Widget()
{
    delete ui;

    if (socket) {
        socket->close();
    }
}

void Widget::receviceMsg(QString msg)
{
    QJsonDocument json = QJsonDocument::fromJson(msg.toUtf8().data());

    if (json.isNull()) {
        ui->plainTextEdit->appendPlainText("收到消息" + msg);
    } else {
        QJsonObject obj = json.object();
        ui->plainTextEdit->appendPlainText("收到来自" + obj["src"].toString() + "的消息" + obj["msg"].toString());
    }
}

void Widget::errorFunc(QAbstractSocket::SocketError err) { ui->plainTextEdit->appendPlainText(socket->origin() + "出错" + socket->errorString()); }

void Widget::on_connect_btn_clicked()
{
    if (!socket) {
        if (ui->name_edit->text().trimmed().isEmpty()) {
            return;
        }

        socket = new QWebSocket(ui->name_edit->text().trimmed(), QWebSocketProtocol::VersionLatest, this);

        //连接
        connect(socket, &QWebSocket::connected, this, [this] {
            ui->plainTextEdit->appendPlainText("已经连接上" + socket->peerAddress().toString());

            isconnect = true;

            ui->connect_btn->setText("断开服务器");
        });

        //断开连接
        connect(socket, &QWebSocket::disconnected, this, [this] {
            ui->plainTextEdit->appendPlainText("连接已断开" + socket->peerAddress().toString());

            isconnect = false;

            ui->connect_btn->setText("连接服务器");
        });

        //错误
        connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(errorFunc(QAbstractSocket::SocketError)));

        //接收消息
        connect(socket, SIGNAL(textMessageReceived(QString)), this, SLOT(receviceMsg(QString)));
    }

    if (!isconnect) {
        socket->open(QUrl(ui->url_edit->text().trimmed()));

    } else {
        socket->close();
        socket->deleteLater();
        socket = nullptr;
    }
}

void Widget::on_send_btn_clicked()
{
    if (!socket) {
        return;
    }

    if (!socket->isValid()) {
        return;
    }

    QString msg = ui->textEdit->toPlainText().trimmed();
    if (msg.isEmpty()) {
        return;
    }

    QString dst = ui->dst_edit->text().trimmed();
    if (dst.isEmpty()) {
        socket->sendTextMessage(msg);
        ui->plainTextEdit->appendPlainText("发送消息" + msg);
    } else {
        QJsonObject obj;

        obj["msg"] = msg;
        obj["src"] = socket->origin();
        obj["dst"] = dst;

        socket->sendTextMessage(QString(QJsonDocument(obj).toJson(QJsonDocument::Compact)));

        ui->plainTextEdit->appendPlainText("向[" + dst + "]发送消息" + msg);
    }
}
