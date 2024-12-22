#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/*
 * QT提供4个处理图像数据，QImage/QPixmap/QBitmap/QPicture
 */
#include <QImage>
#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label_info;

    QImage *img1;
    QImage *img2;
    QImage *img3;

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);
};
#endif  // MAINWINDOW_H
