#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>

#include "qcoreevent.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget* parent = nullptr);
    ~Dialog();

private:
    QLabel* label1;
    QLabel* label2;

    QLabel* label3;
    QLabel* label4;

    QLabel* label5;
    QLabel* label6;

    QLabel* label7;
    QLabel* label8;

    QLabel* label9;
    QLabel* label10;

    QLabel* label11;
    QLabel* label12;

    void resizeEvent(QResizeEvent*);
    void moveEvent(QMoveEvent*);
    void updateLabel();
};
#endif  // DIALOG_H
