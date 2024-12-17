#ifndef WIDGET_H
#define WIDGET_H

#include <QTabWidget>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QTabWidget *tab;
};
#endif  // WIDGET_H
