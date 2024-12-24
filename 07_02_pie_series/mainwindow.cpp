#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //饼状形
    QPieSeries *pie = new QPieSeries();

    //占用比例
    pie->append("70分以下", 30);
    pie->append("70-85分", 40);
    pie->append("86-99分", 20);
    pie->append("100分", 5);

    pie->setLabelsVisible();  //标签可见

    auto red   = pie->slices().at(0);
    auto green = pie->slices().at(1);
    auto blue  = pie->slices().at(2);
    auto black = pie->slices().at(3);

    red->setColor(QColor(255, 0, 0));
    green->setColor(QColor(0, 255, 0));
    blue->setColor(QColor(0, 255, 255));
    black->setColor(QColor(0, 0, 0));

    QChart *chart = new QChart();
    chart->addSeries(pie);
    chart->setTitle("班级分数百分比");

    QChartView *view = new QChartView(chart);

    setCentralWidget(view);
}

MainWindow::~MainWindow() { delete ui; }
