#include "dialog.h"

#include <QGridLayout>
#include <QInputDialog>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowTitle("input dialog");

    btn1 = new QPushButton("学号");
    txt1 = new QLineEdit();

    btn2 = new QPushButton("姓名");
    txt2 = new QLineEdit();

    btn3 = new QPushButton("性别");
    txt3 = new QLineEdit();

    btn4 = new QPushButton("分数");
    txt4 = new QLineEdit();

    auto layout = new QGridLayout();

    layout->addWidget(btn1, 0, 0);
    layout->addWidget(txt1, 0, 1);

    layout->addWidget(btn2, 1, 0);
    layout->addWidget(txt2, 1, 1);

    layout->addWidget(btn3, 2, 0);
    layout->addWidget(txt3, 2, 1);

    layout->addWidget(btn4, 3, 0);
    layout->addWidget(txt4, 3, 1);

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 3);

    connect(btn1, SIGNAL(clicked()), this, SLOT(noclick()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(nameclick()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(sexclick()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(scoreclick()));

    setLayout(layout);
}

Dialog::~Dialog() { delete ui; }

void Dialog::noclick()
{
    auto no = QInputDialog::getText(this, "填写学号", "填写学号");
    if (!no.isEmpty()) {
        txt1->setText(no);
    }
}

void Dialog::nameclick()
{
    auto name = QInputDialog::getText(this, "填写姓名", "填写姓名");
    if (!name.isEmpty()) {
        txt2->setText(name);
    }
}

void Dialog::sexclick()
{
    auto sex = QInputDialog::getItem(this, "选择性别", "选择性别",
                                     QStringList() << "男"
                                                   << "女");
    if (!sex.isEmpty()) {
        txt3->setText(sex);
    }
}

void Dialog::scoreclick()
{
    auto score = QInputDialog::getDouble(this, "填写分数", "填写分数");
    if (score) {
        txt4->setText(QString::number(score));
    }
}
