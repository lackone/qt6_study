#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);

    btn1 = new QPushButton("第一");
    btn1->setFixedHeight(40);
    //设置控件大小策略的方法
    btn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    btn2 = new QPushButton("第二");
    btn2->setFixedWidth(150);
    //设置控件大小策略的方法
    btn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    btn3 = new QPushButton("第三");
    btn3->setFixedHeight(40);
    btn3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    btn4 = new QPushButton("第四");
    btn4->setFixedHeight(40);
    btn4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // addWidget(参数 1，参数 2，参数 3，参数 4，参数 5，参数 6)
    /*
    1:我要插入的子布局对象
    2:插入的开始行
    3:插入的开始列
    4:占用的行数
    5:占用的列数
    6:指定对齐方式
    */
    layout->addWidget(btn1, 0, 1);
    layout->addWidget(btn2, 0, 0, 3, 1);
    layout->addWidget(btn3, 1, 1);
    layout->addWidget(btn4, 2, 1);

    //设置左侧，顶部，右侧，底部，边距
    layout->setContentsMargins(0, 0, 0, 0);

    // pGrid_layouts->setMargin(30);
    // pGrid_layouts->setSpacing(40);

    //设置间隔
    layout->setSpacing(0);

    setLayout(layout);
}

Widget::~Widget() {}
