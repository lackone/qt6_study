#include "dialog.h"

#include <QGridLayout>
#include <QMessageBox>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    label1 = new QLabel("自定义消息框");
    label2 = new QLabel();
    btn    = new QPushButton("测试操作");

    auto layout = new QGridLayout();

    layout->addWidget(label1, 0, 0);
    layout->addWidget(btn, 0, 1);
    layout->addWidget(label2, 1, 0);

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(customMsg()));

    setLayout(layout);
}

Dialog::~Dialog() { delete ui; }

void Dialog::customMsg()
{
    QMessageBox box;
    box.setWindowTitle("我是自定义消息框");

    auto btn1 = box.addButton("YES", QMessageBox::ActionRole);
    auto btn2 = box.addButton("NO", QMessageBox::ActionRole);

    box.setIconPixmap(QPixmap("../../123.jpg"));
    box.setText("我是自定义");
    box.exec();

    if (box.clickedButton() == btn1) {
        label2->setText("点击yes");
    } else if (box.clickedButton() == btn2) {
        label2->setText("点击no");
    }
}
