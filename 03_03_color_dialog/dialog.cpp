#include "dialog.h"

#include <QColorDialog>
#include <QGridLayout>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowTitle("color dialog");

    label    = new QLabel();
    auto pte = label->palette();
    pte.setColor(QPalette::Window, QColor(255, 255, 255));
    label->setAutoFillBackground(true);
    label->setPalette(pte);

    btn = new QPushButton("选择颜色");

    auto layout = new QGridLayout();

    layout->addWidget(label, 0, 0);
    layout->addWidget(btn, 0, 1);

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(getColor()));

    setLayout(layout);
}

Dialog::~Dialog() { delete ui; }

void Dialog::getColor()
{
    auto color = QColorDialog::getColor();
    if (color.isValid()) {
        auto pte = label->palette();
        pte.setColor(QPalette::Window, color);
        label->setAutoFillBackground(true);
        label->setPalette(pte);
    }
}
