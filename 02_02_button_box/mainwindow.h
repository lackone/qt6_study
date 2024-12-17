#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialogButtonBox>
#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QDialogButtonBox *btnbox;
    QPushButton *     btn;

private slots:
    void btnclick(QAbstractButton *btn);
};
#endif  // MAINWINDOW_H
