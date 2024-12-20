#include <QApplication>
#include <QTableView>

#include "mainwindow.h"
#include "modelextend.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    ModelExtend me;
    QTableView  view;
    view.setModel(&me);
    view.setWindowTitle("model_extend");

    view.resize(500, 300);
    view.show();

    return a.exec();
}
