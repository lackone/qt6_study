#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

#include "work.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

const int MAX_NUMS = 3;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QPushButton *start_btn;
    QPushButton *stop_btn;
    QPushButton *exit_btn;

    Work *works[MAX_NUMS];

private slots:
    void startwork();
    void stopwork();
};
#endif  // DIALOG_H
