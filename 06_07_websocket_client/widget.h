#ifndef WIDGET_H
#define WIDGET_H

#include <QAbstractSocket>
#include <QWebSocket>
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

    QWebSocket *socket;
    bool isconnect;

private slots:
    void receviceMsg(QString msg); //接收消息
    void errorFunc(QAbstractSocket::SocketError);
    void on_connect_btn_clicked();
    void on_send_btn_clicked();
};
#endif  // WIDGET_H
