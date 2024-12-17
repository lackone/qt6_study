#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("frame控件测试");

    ui->frame->setStyleSheet("background-color:red");

    ui->frame_2->setStyleSheet("background-color:blue");

    ui->frame->setLineWidth(11);
    ui->frame->setMidLineWidth(11);
    //矩形框
    ui->frame->setFrameShape(QFrame::Box);
    //设置边框阴影
    ui->frame->setFrameShadow(QFrame::Sunken);
}

Widget::~Widget() { delete ui; }
