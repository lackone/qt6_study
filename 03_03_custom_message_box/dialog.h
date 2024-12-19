#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

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

private slots:
    void customMsg();

private:
    Ui::Dialog *ui;

    QLabel *     label1;
    QLabel *     label2;
    QPushButton *btn;
};
#endif  // DIALOG_H
