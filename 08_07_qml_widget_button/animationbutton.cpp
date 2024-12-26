#include "animationbutton.h"

AnimationButton::AnimationButton(QWidget *parent) : QWidget{parent}
{
    enter     = true;
    leave     = false;
    pixWidth  = 0;
    pixHeight = 0;
    oldWidth  = 0;
    oldHeight = 0;

    enterAni = new QPropertyAnimation();
    enterAni->setStartValue(0);
    enterAni->setEndValue(5);
    enterAni->setDuration(200);

    connect(enterAni, SIGNAL(valueChanged(QVariant)), this, SLOT(enterimagechg(QVariant)));

    leaveAni = new QPropertyAnimation();
    leaveAni->setStartValue(0);
    leaveAni->setEndValue(5);
    leaveAni->setDuration(200);

    connect(leaveAni, SIGNAL(valueChanged(QVariant)), this, SLOT(leaveimagechg(QVariant)));
}

AnimationButton::~AnimationButton()
{
    delete enterAni;
    delete leaveAni;
}

void AnimationButton::enterEvent(QEnterEvent *event)
{
    enter     = true;
    leave     = false;
    pixWidth  = pixWidth - 25;
    pixHeight = pixHeight - 25;

    enterAni->start();
}

void AnimationButton::leaveEvent(QEvent *event)
{
    enter = false;
    leave = true;

    pixWidth  = oldWidth;
    pixHeight = oldHeight;

    leaveAni->start();
}

void AnimationButton::paintEvent(QPaintEvent *event)
{
    if (image.isEmpty()) {
        return;
    }

    QPainter pa(this);
    pa.setRenderHint(QPainter::Antialiasing);

    QPixmap pix(image);
    pix = pix.scaled(targetWidth, targetHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    if (enter || leave) {
        int pixx = rect().center().x() - targetWidth / 2;
        int pixy = rect().center().y() - targetHeight / 2;

        QPoint point(pixx, pixy);
        pa.drawPixmap(point, pix);
        pa.drawText(QRectF(0, height() - 20, width(), 20), Qt::AlignCenter, text);
    }
}

void AnimationButton::enterimagechg(QVariant index)
{
    int i        = index.toInt();
    targetWidth  = pixWidth + i * 5;
    targetHeight = pixHeight + i * 5;
    update();
}

void AnimationButton::leaveimagechg(QVariant index)
{
    int i        = index.toInt();
    targetWidth  = pixWidth - i * 5;
    targetHeight = pixHeight - i * 5;
    update();
}

void AnimationButton::settext(QString text) { this->text = text; }

void AnimationButton::setimage(QString image)
{
    this->image = image;

    QPixmap pix(image);
    pixWidth  = pix.width();
    pixHeight = pix.height();
    oldWidth  = pixWidth;
    oldHeight = pixHeight;

    targetWidth  = pixWidth - 25;
    targetHeight = pixHeight - 25;

    update();
}
