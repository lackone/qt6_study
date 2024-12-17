#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QScrollArea>

#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget       w;

    w.resize(300, 300);

    // QScrollArea 有很多功能继承于 QAbstractScrollArea
    QLabel *label = new QLabel();
    // 设置QLabel自动缩放
    label->setScaledContents(true);

    QImage img(":/images/123.jpg");
    label->setPixmap(QPixmap::fromImage(img));

    QScrollArea *area = new QScrollArea;

    //居中
    area->setAlignment(Qt::AlignCenter);

    // 根据窗口比例显示
    // area->setWidgetResizable(true);

    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    area->setWidget(label);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(area, 0, 0);

    w.setLayout(layout);

    w.show();
    return a.exec();
}
