#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
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
    QLineEdit *  txt1;

    QPushButton *btn2;
    QLineEdit *  txt2;

    QPushButton *btn3;
    QLineEdit *  txt3;

    QPushButton *btn4;
    QLineEdit *  txt4;

private slots:
    void noclick();
    void nameclick();
    void sexclick();
    void scoreclick();
};
#endif  // DIALOG_H
