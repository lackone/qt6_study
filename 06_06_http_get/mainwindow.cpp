#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mgr = new QNetworkAccessManager();

    connect(mgr, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishFunc(QNetworkReply*)));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() { mgr->get(QNetworkRequest(QUrl("http://www.baidu.com"))); }

void MainWindow::finishFunc(QNetworkReply* reply)
{
    QString data = reply->readAll();
    ui->plainTextEdit->appendPlainText(data);
    reply->deleteLater();
}
