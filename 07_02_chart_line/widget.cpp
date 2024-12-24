#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    myLineSeries();
}

Widget::~Widget() { delete ui; }

void Widget::myLineSeries()
{
    QChart *chart = new QChart();

    chart->setTitle("全求各国军费增长折线图");

    ui->graphicsView->setChart(chart);

    QValueAxis *ax = new QValueAxis();
    ax->setTitleText("年份");  //标题名称
    ax->setRange(2017, 2021);  //范围
    ax->setLineVisible(true);
    ax->setGridLineVisible(false);  //网络线是否可见

    QValueAxis *ay = new QValueAxis();
    ay->setTitleText("经费(万亿美元)");  //标题名称
    ay->setRange(1000, 10000);           //范围
    ay->setTickCount(10);                //刻度个数
    ay->setLineVisible(true);
    ay->setGridLineVisible(false);  //网络线是否可见

    //折线
    QLineSeries *s1 = new QLineSeries();
    s1->setName("中国");
    s1->setColor(QColor(255, 0, 0));

    //添加数据点
    s1->append(2017, 1000);
    s1->append(2018, 2000);
    s1->append(2019, 3000);
    s1->append(2020, 4000);
    s1->append(2021, 5000);

    chart->addSeries(s1);

    chart->setAxisX(ax, s1);
    chart->setAxisY(ay, s1);

    QLineSeries *s2 = new QLineSeries();
    s2->setName("美国");
    s2->setColor(QColor(255, 255, 0));

    //添加数据点
    s2->append(2017, 4000);
    s2->append(2018, 5000);
    s2->append(2019, 6000);
    s2->append(2020, 7000);
    s2->append(2021, 8000);

    chart->addSeries(s2);

    chart->setAxisX(ax, s2);
    chart->setAxisY(ay, s2);
}
