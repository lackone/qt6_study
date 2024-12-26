#ifndef ANIMATIONBUTTON_H
#define ANIMATIONBUTTON_H

#include <QPainter>
#include <QPropertyAnimation>
#include <QVariant>
#include <QWidget>

class AnimationButton : public QWidget
{
    Q_OBJECT
public:
    explicit AnimationButton(QWidget *parent = nullptr);
    ~AnimationButton();

signals:

    // QWidget interface
protected:
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    bool enter;  //是否进入
    bool leave;  //是否离开
    int  pixWidth;
    int  pixHeight;  //图像高度
    int  oldWidth;
    int  oldHeight;  //原高度

    int targetWidth;
    int targetHeight;  //目标高度

    QString text;   //图像文字
    QString image;  //图像路径

    QPropertyAnimation *enterAni;  //进入动画
    QPropertyAnimation *leaveAni;  //离开动画

public:
    void settext(QString text);
    void setimage(QString image);  //

private slots:
    void enterimagechg(QVariant index);
    void leaveimagechg(QVariant index);
};

#endif  // ANIMATIONBUTTON_H
