#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

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
    QList<QString> getLocalIpAddr();

private slots:
    void on_start_btn_clicked();

    void on_stop_btn_clicked();

    void on_send_btn_clicked();

    void on_broadcast_btn_clicked();

    void readData();

private:
    Ui::MainWindow *ui;

    QUdpSocket *socket;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};
#endif  // MAINWINDOW_H
