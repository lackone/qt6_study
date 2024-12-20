#include "mainwindow.h"

#include <QColorDialog>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    dw = new DrawWidget();

    setCentralWidget(dw);

    initToolBar();

    setMinimumSize(500, 500);

    dw->setStyle(Qt::SolidLine);
    dw->setColor(Qt::black);
    dw->setWidth(spbox->value());
}

MainWindow::~MainWindow() {}

void MainWindow::initToolBar()
{
    auto bar = addToolBar("tool");

    label1 = new QLabel("样式");
    box    = new QComboBox();
    box->addItem("SolidLine", static_cast<int>(Qt::SolidLine));
    box->addItem("DotLine", static_cast<int>(Qt::DotLine));

    connect(box, SIGNAL(activated(int)), this, SLOT(styleChange(int)));

    label2 = new QLabel("线宽");
    spbox  = new QSpinBox();
    spbox->setRange(1, 10);

    connect(spbox, SIGNAL(valueChanged(int)), dw, SLOT(setWidth(int)));

    colorBtn = new QToolButton();
    QPixmap pix(20, 20);
    pix.fill(Qt::black);
    colorBtn->setIcon(QIcon(pix));

    connect(colorBtn, SIGNAL(clicked()), this, SLOT(colorChange()));

    clearBtn = new QToolButton();
    clearBtn->setText("清除");

    connect(clearBtn, SIGNAL(clicked()), dw, SLOT(clear()));

    bar->addWidget(label1);
    bar->addWidget(box);
    bar->addWidget(label2);
    bar->addWidget(spbox);
    bar->addWidget(colorBtn);
    bar->addWidget(clearBtn);
}

void MainWindow::styleChange(int index) { dw->setStyle(box->itemData(index).toInt()); }

void MainWindow::colorChange()
{
    auto color = QColorDialog::getColor(Qt::black, this);
    if (color.isValid()) {
        dw->setColor(color);
        QPixmap pix(20, 20);
        pix.fill(color);
        colorBtn->setIcon(QIcon(pix));
    }
}
