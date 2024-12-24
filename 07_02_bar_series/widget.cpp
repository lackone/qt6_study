#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QBarSet *bar = new QBarSet("bar");

    *bar << 111 << 222 << 333 << 444 << 555;

    QStackedBarSeries *ser = new QStackedBarSeries();
    ser->append(bar);

    QChart *chart = new QChart();
    chart->addSeries(ser);
    chart->setTitle("学校高考成绩分数");

    QStringList list = {"小五", "小李", "小张", "小赵", "小明"};

    //将类型添加到图表的轴
    QBarCategoryAxis *ax = new QBarCategoryAxis();
    ax->append(list);
    ax->setTitleText("考生姓名");
    chart->addAxis(ax, Qt::AlignBottom);

    QValueAxis *ay = new QValueAxis();
    ay->setRange(0, 750);
    ay->setTitleText("总分阶梯");
    chart->addAxis(ay, Qt::AlignLeft);

    ser->attachAxis(ax);
    ser->attachAxis(ay);

    chart->legend()->setVisible(false);  //
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *view = new QChartView(chart);

    view->resize(size());
    view->show();
}

Widget::~Widget() { delete ui; }
