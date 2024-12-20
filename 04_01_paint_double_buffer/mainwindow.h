#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QLabel>
#include <QMainWindow>
#include <QSpinBox>
#include <QToolButton>

#include "drawwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initToolBar();

private:
    DrawWidget *dw;

    QLabel *   label1;  //线样式
    QComboBox *box;

    QLabel *  label2;  //线宽
    QSpinBox *spbox;

    QToolButton *colorBtn;
    QToolButton *clearBtn;

private slots:
    void styleChange(int);
    void colorChange();
};
#endif  // MAINWINDOW_H
