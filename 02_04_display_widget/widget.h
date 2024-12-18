#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QTimer>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void labelfunc();
    void textBrowserfunc();
    void progressBarfunc();
    void inittime();
private slots:
    void on_pushButton_clicked();

    void on_start_clicked();

    void on_pushButton_3_clicked();

    void on_reset_clicked();

    void on_pause_clicked();

    void timeout();

private:
    Ui::Widget *ui;

    QLabel *label;

    QTimer *time;
    int     ival;
};
#endif  // WIDGET_H
