#ifndef WIDGET_H
#define WIDGET_H

#include <QAbstractSocket>  //qtcpsocket和qudpsocket基类
#include <QJsonDocument>    //JSON读写
#include <QJsonObject>      //json对象
#include <QWebSocket>
#include <QWebSocketServer>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QWebSocketServer *  server;
    QList<QWebSocket *> socket_list;

public slots:
    void getnewConnect();
    void msgReceived(QString);
    void onerrorFunc(QAbstractSocket::SocketError);
private slots:
    void on_send_btn_clicked();
};
#endif  // WIDGET_H
