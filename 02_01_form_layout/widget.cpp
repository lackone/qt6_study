#include "widget.h"

#include <QFormLayout>
#include <QLineEdit>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 300);

    setWindowTitle("表单布局");

    auto form = new QFormLayout(this);

    auto txt1 = new QLineEdit();
    auto txt2 = new QLineEdit();
    auto txt3 = new QLineEdit();
    auto txt4 = new QLineEdit();

    form->addRow("学号", txt1);
    form->addRow("姓名", txt2);
    form->addRow("地址", txt3);
    form->addRow("备注", txt4);

    form->setSpacing(10);

    // WrapAllRows 将标签显示在单行编辑框上面
    // qLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);

    // 当标签和单选编辑框,将标签显示在同一行。
    form->setRowWrapPolicy(QFormLayout::WrapLongRows);

    //标签对齐方式
    form->setLabelAlignment(Qt::AlignLeft);
}

Widget::~Widget() {}
