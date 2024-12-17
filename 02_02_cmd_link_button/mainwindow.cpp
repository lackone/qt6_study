#include "mainwindow.h"

#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setGeometry(300, 300, 400, 300);

    setStyleSheet("QMainWindow{background-color:red;}");

    linkbtn = new QCommandLinkButton("link", "linklink", this);
    linkbtn->setGeometry(30, 30, 100, 60);

    connect(linkbtn, SIGNAL(clicked()), this, SLOT(linkClick()));
}

MainWindow::~MainWindow() {}

void MainWindow::linkClick() { QDesktopServices::openUrl(QUrl("http://www.baidu.com")); }
