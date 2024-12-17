#ifndef WIDGET_H
#define WIDGET_H

#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QGridLayout *layout;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
};
#endif  // WIDGET_H
