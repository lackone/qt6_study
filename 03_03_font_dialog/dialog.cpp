#include "dialog.h"

#include <QFontDialog>
#include <QGridLayout>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    txt = new QLineEdit();
    txt->setText("hello,world");
    btn = new QPushButton("选择字体");

    auto layout = new QGridLayout();

    layout->addWidget(txt, 0, 0);
    layout->addWidget(btn, 0, 1);

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(settxtFont()));

    setLayout(layout);
}

Dialog::~Dialog() { delete ui; }

void Dialog::settxtFont()
{
    bool ok;
    auto font = QFontDialog::getFont(&ok);
    if (ok) {
        txt->setFont(font);
    }
}
