#include "mainwindow.h"

#include <QGridLayout>
#include <QMouseEvent>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label1 = new QLabel();
    img1   = new QImage();
    img1->load("../../a.jpg");                                  //加载图片
    label1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  //居中对齐
    label1->setPixmap(QPixmap::fromImage(*img1));

    label2 = new QLabel();
    img2   = new QImage();
    img2->load("../../b.jpg");
    label2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label2->setPixmap(QPixmap::fromImage(*img2));

    label3 = new QLabel();
    img3   = new QImage();
    img3->load("../../c.jpg");
    label3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label3->setPixmap(QPixmap::fromImage(*img3));

    label_info = new QLabel("鼠标按下提示");
    label_info->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    auto layout = new QGridLayout();

    layout->addWidget(label1, 0, 0);
    layout->addWidget(label2, 0, 1);
    layout->addWidget(label3, 0, 2);

    layout->addWidget(label_info, 1, 0, 1, 3);

    auto wid = new QWidget();
    wid->setLayout(layout);

    //安装事件过滤
    label1->installEventFilter(this);
    label2->installEventFilter(this);
    label3->installEventFilter(this);

    setCentralWidget(wid);
}

MainWindow::~MainWindow() { delete ui; }

/*
    事件过滤
*/
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == label1) {
        if (event->type() == QEvent::MouseButtonPress)  //鼠标点击
        {
            auto ev = (QMouseEvent *)event;
            if (ev->buttons() & Qt::LeftButton) {
                label_info->setText("鼠标左键按下，左边图片");
            } else if (ev->buttons() & Qt::MiddleButton) {
                label_info->setText("鼠标中键按下，左边图片");
            } else if (ev->buttons() & Qt::RightButton) {
                label_info->setText("鼠标右键按下，左边图片");
            }

            QImage img = img1->scaled(img1->width() * 2, img1->height() * 2);
            label1->setPixmap(QPixmap::fromImage(img));
        } else if (event->type() == QEvent::MouseButtonRelease) {
            label_info->setText("鼠标释放，左边图片");
            label1->setPixmap(QPixmap::fromImage(*img1));
        }
    }

    if (watched == label2) {
        if (event->type() == QEvent::MouseButtonPress)  //鼠标点击
        {
            auto ev = (QMouseEvent *)event;
            if (ev->buttons() & Qt::LeftButton) {
                label_info->setText("鼠标左键按下，中间图片");
            } else if (ev->buttons() & Qt::MiddleButton) {
                label_info->setText("鼠标中键按下，中间图片");
            } else if (ev->buttons() & Qt::RightButton) {
                label_info->setText("鼠标右键按下，中间图片");
            }

            QImage img = img2->scaled(img2->width() * 2, img2->height() * 2);
            label2->setPixmap(QPixmap::fromImage(img));
        } else if (event->type() == QEvent::MouseButtonRelease) {
            label_info->setText("鼠标释放，中间图片");
            label2->setPixmap(QPixmap::fromImage(*img2));
        }
    }

    if (watched == label3) {
        if (event->type() == QEvent::MouseButtonPress)  //鼠标点击
        {
            auto ev = (QMouseEvent *)event;
            if (ev->buttons() & Qt::LeftButton) {
                label_info->setText("鼠标左键按下，右边图片");
            } else if (ev->buttons() & Qt::MiddleButton) {
                label_info->setText("鼠标中键按下，右边图片");
            } else if (ev->buttons() & Qt::RightButton) {
                label_info->setText("鼠标右键按下，右边图片");
            }

            QImage img = img3->scaled(img3->width() * 2, img3->height() * 2);
            label3->setPixmap(QPixmap::fromImage(img));
        } else if (event->type() == QEvent::MouseButtonRelease) {
            label_info->setText("鼠标释放，右边图片");
            label3->setPixmap(QPixmap::fromImage(*img3));
        }
    }

    return QMainWindow::eventFilter(watched, event);
}
