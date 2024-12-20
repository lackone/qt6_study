#include "paintwidget.h"

#include <QPainter>

PaintWidget::PaintWidget(QWidget *parent) : QWidget{parent}
{
    setPalette(QPalette(Qt::red));

    setAutoFillBackground(true);  //设置背景色

    setMinimumSize(500, 500);  //设置最小大小
}

void PaintWidget::setType(type t)
{
    tp = t;
    update();
}

void PaintWidget::setPen(QPen p)
{
    pen = p;
    update();
}

void PaintWidget::setBrush(QBrush b)
{
    brush = b;
    update();
}

void PaintWidget::setFillRule(Qt::FillRule r)
{
    rule = r;
    update();
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setPen(pen);

    p.setBrush(brush);

    QRect re(10, 10, 200, 200);

    switch (tp) {
        case Line:
            p.drawLine(re.topLeft(), re.bottomRight());
            break;
        case Rect:
            p.drawRect(re);
            break;
    }
}
