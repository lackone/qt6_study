#include "mainwindow.h"

#include <QChartView>
#include <QtCharts>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1、创建图表对象
    auto view = new QChartView();

    QChart *chart = new QChart();

    chart->setTitle("图表测试");

    // 2、将图表添加到视图
    view->setChart(chart);

    // 3、将图表视图展示到窗口中间
    this->setCentralWidget(view);

    // 4、创建曲线
    QLineSeries *s1 = new QLineSeries();
    QLineSeries *s2 = new QLineSeries();

    s1->setName("正弦");
    s2->setName("余弦");

    // 5、将曲线添加到图表
    chart->addSeries(s1);
    chart->addSeries(s2);

    // 6、为曲线添加对应的数值
    qreal t = 0, y1, y2, iv = 0.1;

    for (int i = 0; i < 100; i++) {
        y1 = qSin(t);
        s1->append(t, y1);
        y2 = qSin(t + 20);
        s2->append(t, y2);

        t = t + iv;
    }

    // 7、创建坐标轴
    QValueAxis *ax = new QValueAxis;  // x轴
    ax->setRange(0, 10);              //坐标轴范围
    ax->setTitleText("aaa");

    QValueAxis *ay = new QValueAxis;
    ay->setRange(-2, 2);
    ay->setTitleText("bbb");

    chart->setAxisX(ax, s1);
    chart->setAxisY(ay, s1);

    chart->setAxisX(ax, s2);
    chart->setAxisY(ay, s2);
}

MainWindow::~MainWindow() { delete ui; }
