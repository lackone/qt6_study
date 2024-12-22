#ifndef DIALOG_H
#define DIALOG_H

#include <QAbstractSocket>
#include <QDialog>
#include <QHostInfo>

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

    QString protocolTypeName(QAbstractSocket::NetworkLayerProtocol pro);

private slots:
    void lookupHostInfo(const QHostInfo &info);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};
#endif  // DIALOG_H
