#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCommandLinkButton>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QCommandLinkButton *linkbtn;

private slots:
    void linkClick();
};
#endif  // MAINWINDOW_H
