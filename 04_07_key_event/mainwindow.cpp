#include "mainwindow.h"

#include <QKeyEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(500, 500);

    step = 10;

    wid = new QWidget();

    label        = new QLabel(wid);
    QPixmap *pix = new QPixmap(50, 50);
    pix->fill(Qt::red);
    label->setGeometry(10, 10, 50, 50);
    label->setPixmap(*pix);

    auto pte = wid->palette();
    pte.setColor(QPalette::Window, Qt::green);
    wid->setAutoFillBackground(true);
    wid->setPalette(pte);

    setCentralWidget(wid);
}

MainWindow::~MainWindow() {}

void MainWindow::drawLine()
{
    qDebug() << size();

    QPixmap *pix = new QPixmap(size());

    QPainter *pa = new QPainter();

    QPen pen(Qt::DashDotLine);

    qDebug() << 11111111111;

    for (int i = step; i < width(); i += step) {
        pa->begin(pix);
        pa->setPen(pen);
        pa->drawLine(QPoint(i, 0), QPoint(i, height()));
        pa->end();
    }

    qDebug() << 22222222222;

    for (int j = step; j < height(); j += step) {
        pa->begin(pix);
        pa->setPen(pen);
        pa->drawLine(QPoint(0, j), QPoint(width(), j));
        pa->end();
    }

    qDebug() << 33333333333;

    pa->begin(wid);
    pa->drawImage(0, 0, pix->toImage());
    pa->end();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << label->x() << label->y();
    qDebug() << width() << height();

    if (event->key() == Qt::Key_Right && ((label->x() + step) > (width() - label->width()))) {
        return;
    }
    if (event->key() == Qt::Key_Down && ((label->y() + step) > (height() - label->height()))) {
        return;
    }
    if (event->key() == Qt::Key_Left && label->x() <= 0) {
        return;
    }
    if (event->key() == Qt::Key_Up && label->y() <= 0) {
        return;
    }

    if (event->key() == Qt::Key_Left) {
        label->move(label->x() - step, label->y());
    } else if (event->key() == Qt::Key_Right) {
        label->move(label->x() + step, label->y());
    } else if (event->key() == Qt::Key_Up) {
        label->move(label->x(), label->y() - step);
    } else if (event->key() == Qt::Key_Down) {
        label->move(label->x(), label->y() + step);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    qDebug() << "test";
    drawLine();
}
