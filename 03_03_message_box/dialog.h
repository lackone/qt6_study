#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
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

private:
    Ui::Dialog *ui;

    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;

private slots:
    void btn1click();
    void btn2click();
    void btn3click();
    void btn4click();
    void btn5click();
    void btn6click();
};
#endif  // DIALOG_H
