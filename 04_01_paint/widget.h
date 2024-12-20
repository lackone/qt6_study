#ifndef WIDGET_H
#define WIDGET_H

#include <QComboBox>
#include <QLabel>
#include <QWidget>

#include "paintwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    PaintWidget *pw;
    QComboBox *  box;
    QLabel *     label;

private slots:
    void boxChange(int);
};
#endif  // WIDGET_H
