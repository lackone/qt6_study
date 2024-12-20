#include "widget.h"

#include <QGridLayout>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    pw = new PaintWidget();

    auto pen = new QPen();
    pen->setColor(QColor(255, 255, 0));

    pw->setPen(*pen);

    auto layout = new QGridLayout();

    label = new QLabel("选择形状");

    box = new QComboBox();
    box->addItem("线", 33);
    box->addItem("矩形", PaintWidget::Rect);

    layout->addWidget(pw, 0, 0);
    layout->addWidget(label, 0, 1);
    layout->addWidget(box, 0, 2);

    connect(box, SIGNAL(currentIndexChanged(int)), this, SLOT(boxChange(int)));

    setLayout(layout);
}

Widget::~Widget() {}

void Widget::boxChange(int index)
{
    auto v = box->itemData(index);

    qDebug() << v;

    if (v.toInt() == PaintWidget::Line) {
        pw->setType(PaintWidget::Line);
    } else if (v.toInt() == PaintWidget::Rect) {
        pw->setType(PaintWidget::Rect);
    }
}
