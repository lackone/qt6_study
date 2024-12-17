#include <QApplication>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog       w;

    w.setWindowTitle("计算球的体积");

    w.show();
    return a.exec();
}
