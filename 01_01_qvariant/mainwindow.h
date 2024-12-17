#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

typedef struct _Person
{
    int     no;
    QString name;
    double  score;
} Person, *PPerson;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif  // MAINWINDOW_H
