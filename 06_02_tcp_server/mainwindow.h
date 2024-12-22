#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_btn_clicked();

    void on_stop_btn_clicked();

    void on_send_btn_clicked();

    void newConnection();
    void clientConnect();
    void clientdisconnect();
    void clientreaddata();
    void clientstatechange(QAbstractSocket::SocketState);

private:
    Ui::MainWindow *ui;

    QTcpServer *   server;            // tcp服务器
    QTcpSocket *   socket;            //通讯socket
    QList<QString> getLocalIpAddr();  //获取本机IP

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};
#endif  // MAINWINDOW_H
