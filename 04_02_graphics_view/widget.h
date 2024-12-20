#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

#include "pixitem.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void createControlFrame();  //创建控件
private:
    int   angle;  //角度
    qreal scale;  //缩放
    qreal tilt;   //倾斜

    QGraphicsView *view;
    QFrame *       frame;
    PixItem *      pixitem;

private slots:
    void rotatefunc(int);  //旋转
    void scalefunc(int);   //缩放
    void tiltfunc(int);    //倾斜
};
#endif  // WIDGET_H
