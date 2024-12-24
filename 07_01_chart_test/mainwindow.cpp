#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSplineSeries *s1 = new QSplineSeries();

    s1->setName("曲线");

    //添加点
    s1->append(0, 5);
    s1->append(1, 3);

    QChart *chart = ui->graphicsView->chart();
    chart->legend()->hide();  //隐藏图表比例

    chart->addSeries(s1);
    chart->setTitle("图表标题");
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 20);  //设置y轴
}

MainWindow::~MainWindow() { delete ui; }
