#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("图形视图框架");

    angle = 0;
    scale = 2;
    tilt  = 2;

    //场景
    QGraphicsScene *scene = new QGraphicsScene();

    //设置场景的矩形区域
    scene->setSceneRect(-200, -200, 380, 380);

    QPixmap *pix = new QPixmap();
    pix->load("../../1.jpg");

    pixitem = new PixItem(pix);

    //添加图元
    scene->addItem(pixitem);
    pixitem->setPos(0, 0);

    //视图
    view = new QGraphicsView();
    view->setScene(scene);
    view->setMinimumSize(800, 600);

    frame = new QFrame();

    createControlFrame();

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(view);
    hlayout->addWidget(frame);

    setLayout(hlayout);
}

Widget::~Widget() {}

void Widget::createControlFrame()
{
    //旋转
    QSlider *rotateSlider = new QSlider();
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setRange(0, 360);

    QHBoxLayout *rotateLayout = new QHBoxLayout();
    rotateLayout->addWidget(rotateSlider);

    QGroupBox *rotateGroup = new QGroupBox("旋转");
    rotateGroup->setLayout(rotateLayout);

    //缩放
    QSlider *scaleSlider = new QSlider();
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0, 2 * scale);

    QHBoxLayout *scaleLayout = new QHBoxLayout();
    scaleLayout->addWidget(scaleSlider);

    QGroupBox *scaleGroup = new QGroupBox("缩放");
    scaleGroup->setLayout(scaleLayout);

    //倾斜
    QSlider *tiltSlider = new QSlider();
    tiltSlider->setOrientation(Qt::Horizontal);
    tiltSlider->setRange(0, 2 * tilt);

    QHBoxLayout *tiltLayout = new QHBoxLayout();
    tiltLayout->addWidget(tiltSlider);

    QGroupBox *tiltGroup = new QGroupBox("倾斜");
    tiltGroup->setLayout(tiltLayout);

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(rotateGroup);
    vlayout->addWidget(scaleGroup);
    vlayout->addWidget(tiltGroup);

    connect(rotateSlider, SIGNAL(valueChanged(int)), this, SLOT(rotatefunc(int)));
    connect(scaleSlider, SIGNAL(valueChanged(int)), this, SLOT(scalefunc(int)));
    connect(tiltSlider, SIGNAL(valueChanged(int)), this, SLOT(tiltfunc(int)));

    frame->setLayout(vlayout);
}

void Widget::rotatefunc(int val)
{
    qDebug() << "rotatefunc:" << val;
    qDebug() << "rotatefunc:" << angle;
    view->rotate(val - angle);
    angle = val;
}

void Widget::scalefunc(int val)
{
    qDebug() << "scalefunc:" << val;
    qreal qs;
    if (val > scale) {
        qs = pow(1.1, (val - scale));
    } else {
        qs = pow(1 / 1.1, (scale - val));
    }
    view->scale(qs, qs);
    scale = val;
}

void Widget::tiltfunc(int val)
{
    qDebug() << "tiltfunc:" << val;
    view->shear((val - tilt) / 2.0, 0);
    tilt = val;
}
