#include "widget.h"

#include <QFile>

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    labelfunc();

    textBrowserfunc();

    progressBarfunc();

    inittime();
}

Widget::~Widget() { delete ui; }

void Widget::labelfunc()
{
    QString fpath("../../666.jpg");

    QImage *img = new QImage;

    //加载图片
    if (!img->load(fpath)) {
        delete img;
        return;
    }

    ui->label->setPixmap(QPixmap::fromImage(*img));
    //缩放
    ui->label->setScaledContents(true);
}

void Widget::textBrowserfunc()
{
    QFile re("../../test.txt");

    if (!re.open(QFile::ReadOnly | QFile::Text)) {
        return;
    }

    while (!re.atEnd()) {
        auto    by = re.readLine();
        QString str(by);
        ui->textBrowser->append(str);
    }
}

void Widget::progressBarfunc()
{
    ui->progressBar->setRange(1, 1000);
    ui->progressBar->setValue(100);
}

void Widget::on_pushButton_clicked()
{
    for (int i = 1; i < 1000; i++) {
        ui->progressBar->setValue(i);
    }
}

void Widget::inittime()
{
    time = new QTimer();
    time->setInterval(1000);
    time->stop();

    ival = 0;

    connect(time, SIGNAL(timeout()), this, SLOT(timeout()));
}

void Widget::on_start_clicked() { time->start(); }

void Widget::on_reset_clicked()
{
    time->stop();
    ival = 0;
}

void Widget::on_pause_clicked() { time->stop(); }

void Widget::timeout()
{
    ival++;
    ui->lcdNumber->display(ival);
}
