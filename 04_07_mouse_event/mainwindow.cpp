#include "mainwindow.h"

#include <QLabel>
#include <QMouseEvent>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(500, 300);

    QStatusBar *bar = new QStatusBar();

    label1 = new QLabel("当前的坐标为：");
    label1->setFixedWidth(200);
    label2 = new QLabel();
    label2->setFixedWidth(200);
    label3 = new QLabel();
    label3->setFixedWidth(200);

    bar->addWidget(label1);
    bar->addWidget(label2);
    bar->addWidget(label3);

    //鼠标跟踪
    setMouseTracking(true);

    setStatusBar(bar);
}

MainWindow::~MainWindow() {}

//鼠标移动
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    label3->setText("鼠标移动");

    label2->setText(QString("%1 , %2").arg(event->x()).arg(event->y()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QString str;
    if (event->button() == Qt::LeftButton) {
        str = "左键";
    } else if (event->button() == Qt::MiddleButton) {
        str = "中键";
    } else if (event->button() == Qt::RightButton) {
        str = "右键";
    }

    label3->setText("鼠标" + str + "按下");

    label2->setText(QString("%1 , %2").arg(event->x()).arg(event->y()));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QString str;
    if (event->button() == Qt::LeftButton) {
        str = "左键";
    } else if (event->button() == Qt::MiddleButton) {
        str = "中键";
    } else if (event->button() == Qt::RightButton) {
        str = "右键";
    }

    label3->setText("鼠标" + str + "释放");

    label2->setText(QString("%1 , %2").arg(event->x()).arg(event->y()));
}
