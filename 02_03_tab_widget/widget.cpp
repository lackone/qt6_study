#include "widget.h"

#include <QLabel>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setGeometry(300, 300, 400, 300);

    setWindowTitle("标签");

    tab = new QTabWidget(this);
    tab->setGeometry(0, 0, 400, 300);
    tab->show();

    QWidget *wid1 = new QWidget();
    tab->addTab(wid1, "tab1");

    QLabel *label1 = new QLabel(wid1);
    label1->setText("111111");

    QWidget *wid2 = new QWidget();
    tab->addTab(wid2, "tab2");

    QLabel *label2 = new QLabel(wid2);
    label2->setText("222222");

    QWidget *wid3 = new QWidget();
    tab->addTab(wid3, "tab3");

    QLabel *label3 = new QLabel(wid3);
    label3->setText("333333");
}

Widget::~Widget() {}
