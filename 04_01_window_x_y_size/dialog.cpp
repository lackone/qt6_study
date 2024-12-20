#include "dialog.h"

#include <QGridLayout>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    auto layout = new QGridLayout();

    resize(500, 300);

    label1 = new QLabel("geometry()");
    label2 = new QLabel();

    label3 = new QLabel("width()");
    label4 = new QLabel();

    label5 = new QLabel("height()");
    label6 = new QLabel();

    label7 = new QLabel("rect()");
    label8 = new QLabel();

    label9  = new QLabel("size()");
    label10 = new QLabel();

    label11 = new QLabel("frameGeometry()");
    label12 = new QLabel();

    layout->addWidget(label1, 0, 0);
    layout->addWidget(label2, 0, 1);

    layout->addWidget(label3, 1, 0);
    layout->addWidget(label4, 1, 1);

    layout->addWidget(label5, 2, 0);
    layout->addWidget(label6, 2, 1);

    layout->addWidget(label7, 3, 0);
    layout->addWidget(label8, 3, 1);

    layout->addWidget(label9, 4, 0);
    layout->addWidget(label10, 4, 1);

    layout->addWidget(label11, 5, 0);
    layout->addWidget(label12, 5, 1);

    setLayout(layout);
}

Dialog::~Dialog() {}

void Dialog::resizeEvent(QResizeEvent *ev)
{
    qDebug() << ev;

    updateLabel();
}

void Dialog::moveEvent(QMoveEvent *ev)
{
    qDebug() << ev;

    updateLabel();
}

void Dialog::updateLabel()
{
    auto geo    = this->geometry();
    auto width  = this->width();
    auto height = this->height();
    auto rect   = this->rect();
    auto size   = this->size();
    auto fgeo   = this->frameGeometry();

    label2->setText(QString("%1 %2 %3 %4").arg(geo.x()).arg(geo.y()).arg(geo.width()).arg(geo.height()));

    label4->setText(QString("%1").arg(width));

    label6->setText(QString("%1").arg(height));

    label8->setText(QString("%1 %2 %3 %4").arg(rect.x()).arg(rect.y()).arg(rect.width()).arg(rect.height()));

    label10->setText(QString("%1 %2").arg(size.width()).arg(size.height()));

    label12->setText(QString("%1 %2 %3 %4").arg(fgeo.x()).arg(fgeo.y()).arg(fgeo.width()).arg(fgeo.height()));
}
