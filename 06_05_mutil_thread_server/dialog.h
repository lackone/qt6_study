#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
class ClientServer;

#include "clientserver.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    int           cnt;     //统计客户端访问次数
    ClientServer *server;  //服务对象
public slots:
    void handleCnt();
};
#endif  // DIALOG_H
