#include "widget.h"

#include <QCheckBox>
#include <QGroupBox>
#include <QMenu>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setGeometry(300, 300, 400, 300);

    //组合框一
    auto *grp = new QGroupBox("互相排拆单选", this);

    auto *radio1 = new QRadioButton("男", this);
    auto *radio2 = new QRadioButton("女", this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(radio1);
    layout->addWidget(radio2);
    grp->setLayout(layout);

    //组合框二
    auto *grp2 = new QGroupBox("多选", this);
    auto *chk1 = new QCheckBox("chk1");
    auto *chk2 = new QCheckBox("chk2");
    auto *chk3 = new QCheckBox("chk3");

    QVBoxLayout *layout2 = new QVBoxLayout();
    layout2->addWidget(chk1);
    layout2->addWidget(chk2);
    layout2->addWidget(chk3);
    grp2->setLayout(layout2);

    //组合框三
    auto *grp3 = new QGroupBox("互相排拆单选", this);
    grp3->setCheckable(true);

    auto *radio11 = new QRadioButton("radio11", this);
    auto *radio22 = new QRadioButton("radio22", this);
    auto *radio33 = new QRadioButton("radio33", this);
    auto *chk44   = new QCheckBox("chk44");
    chk44->setChecked(true);

    QVBoxLayout *layout3 = new QVBoxLayout();
    layout3->addWidget(radio11);
    layout3->addWidget(radio22);
    layout3->addWidget(radio33);
    layout3->addWidget(chk44);
    grp3->setLayout(layout3);

    //组合框四
    auto *grp4 = new QGroupBox("互相排拆单选", this);
    grp4->setCheckable(true);
    grp4->setChecked(true);

    auto *radio55 = new QRadioButton("radio55", this);
    auto *radio66 = new QRadioButton("radio66", this);
    auto *btn77   = new QPushButton("btn77", this);

    //添加菜单
    QMenu *menu = new QMenu(this);
    menu->addAction("a1");
    menu->addAction("a2");
    menu->addAction("a3");
    btn77->setMenu(menu);

    radio55->setCheckable(true);
    radio55->setChecked(true);

    QVBoxLayout *layout4 = new QVBoxLayout();
    layout4->addWidget(radio55);
    layout4->addWidget(radio66);
    layout4->addWidget(btn77);
    grp4->setLayout(layout4);

    QGridLayout *grid = new QGridLayout();

    grid->addWidget(grp, 0, 0);
    grid->addWidget(grp2, 0, 1);
    grid->addWidget(grp3, 1, 0);
    grid->addWidget(grp4, 1, 1);

    setLayout(grid);
}

Widget::~Widget() {}
