#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QBrush>  //画刷
#include <QPen>    //钢笔
#include <QWidget>

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);

    enum type
    {
        Line,
        Rect
    };

    void setType(type);
    void setPen(QPen);
    void setBrush(QBrush);
    void setFillRule(Qt::FillRule);

signals:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

private:
    type         tp;
    QPen         pen;
    QBrush       brush;
    Qt::FillRule rule;
};

#endif  // PAINTWIDGET_H
