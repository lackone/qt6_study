#include "drawwidget.h"

#include <QMouseEvent>
#include <QPainter>

DrawWidget::DrawWidget(QWidget *parent) : QWidget{parent}
{
    img = new QPixmap(size());
    img->fill(Qt::white);
    update();
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.drawPixmap(QPoint(0, 0), *img);
}

void DrawWidget::mousePressEvent(QMouseEvent *event) { start_pos = event->pos(); }

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPainter p;
    QPen     pen;
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(ww);
    pen.setColor(color);

    p.begin(img);
    p.setPen(pen);
    p.drawLine(start_pos, event->pos());
    p.end();

    start_pos = event->pos();

    update();
}

void DrawWidget::resizeEvent(QResizeEvent *event)
{
    if (height() > img->height() || width() > img->width()) {
        QPixmap *p = new QPixmap(size());
        p->fill(Qt::white);

        QPainter ps(p);
        ps.drawPixmap(QPoint(0, 0), *img);
        img = p;
        update();
    }

    QWidget::resizeEvent(event);
}

void DrawWidget::setStyle(int s)
{
    style = s;
    update();
}

void DrawWidget::setWidth(int w)
{
    ww = w;
    update();
}

void DrawWidget::setColor(QColor c)
{
    color = c;
    update();
}

void DrawWidget::clear()
{
    img = new QPixmap(size());
    img->fill(Qt::white);
    update();
}
