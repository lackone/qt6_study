#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    //创建标签
    label1 = new QLabel("请输入圆球的半径:", this);

    label2 = new QLabel("", this);

    //创建文本框
    txt = new QLineEdit(this);

    //创建按钮
    btn = new QPushButton("计算圆球体积", this);

    //创建网格布局
    layout = new QGridLayout(this);

    //添加组件
    layout->addWidget(label1, 0, 0);
    layout->addWidget(txt, 0, 1);
    layout->addWidget(label2, 1, 0);
    layout->addWidget(btn, 1, 1);

    //添加信号与槽
    connect(btn, SIGNAL(clicked()), this, SLOT(calc()));
}

Dialog::~Dialog() {}

void Dialog::calc()
{
    double r   = txt->text().toDouble();
    double sum = (4.0 / 3.0) * PI * r * r * r;

    label2->setText(QString("%1").arg(sum));
}
