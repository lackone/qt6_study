#include "dialog.h"

#include <QGridLayout>
#include <QMessageBox>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    btn1 = new QPushButton("问题");
    btn2 = new QPushButton("信息");
    btn3 = new QPushButton("警告");
    btn4 = new QPushButton("错误");
    btn5 = new QPushButton("关于");
    btn6 = new QPushButton("关于QT");

    auto layout = new QGridLayout();

    layout->addWidget(btn1, 0, 0);
    layout->addWidget(btn2, 0, 1);
    layout->addWidget(btn3, 1, 0);
    layout->addWidget(btn4, 1, 1);
    layout->addWidget(btn5, 2, 0);
    layout->addWidget(btn6, 2, 1);

    connect(btn1, SIGNAL(clicked()), this, SLOT(btn1click()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(btn2click()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(btn3click()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(btn4click()));
    connect(btn5, SIGNAL(clicked()), this, SLOT(btn5click()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(btn6click()));

    setLayout(layout);
}

Dialog::~Dialog() { delete ui; }

void Dialog::btn1click()
{
    auto ret = QMessageBox::question(this, "你是中国人吗？", "你是中国人吗？");
    if (ret == QMessageBox::Yes) {
        QMessageBox::information(this, "是", "是");
    } else {
        QMessageBox::information(this, "否", "否");
    }
}

void Dialog::btn2click() { QMessageBox::information(this, "信息", "我是信息框"); }

void Dialog::btn3click() { QMessageBox::warning(this, "警告", "警告"); }

void Dialog::btn4click() { QMessageBox::critical(this, "错误", "错误"); }

void Dialog::btn5click() { QMessageBox::about(this, "关于", "关于"); }

void Dialog::btn6click() { QMessageBox::aboutQt(this, "关于QT"); }
