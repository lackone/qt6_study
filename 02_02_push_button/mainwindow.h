#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *btn1;
    QPushButton *btn2;

private slots:
    void btn1_click();
    void btn2_click();
};
#endif  // MAINWINDOW_H
