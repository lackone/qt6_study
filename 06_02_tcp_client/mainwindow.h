#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHostInfo>
#include <QMainWindow>
#include <QTcpSocket>

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

private:
    Ui::MainWindow *ui;

    QTcpSocket *   socket;            //通讯socket
    QList<QString> getLocalIpAddr();  //获取本机IP

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_connect_btn_clicked();
    void on_stop_btn_clicked();
    void on_send_btn_clicked();

    void connectserver();     //连接服务端
    void disconnectserver();  //断开服务端
    void serverreaddata();    //读取服务端数据
};
#endif  // MAINWINDOW_H
