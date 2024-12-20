#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QPen>
#include <QWidget>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);

signals:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);

public slots:
    void setStyle(int);
    void setWidth(int);
    void setColor(QColor);
    void clear();  //清除

private:
    QPixmap *img;
    QPoint   start_pos;
    QPoint   end_pos;
    QColor   color;
    int      style;
    int      ww;
};

#endif  // DRAWWIDGET_H
