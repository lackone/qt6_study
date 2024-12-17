#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

const double PI = 3.1415926;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QGridLayout *layout;
    QLabel *     label1;
    QLabel *     label2;
    QLineEdit *  txt;
    QPushButton *btn;

private slots:
    void calc();
};
#endif  // DIALOG_H
