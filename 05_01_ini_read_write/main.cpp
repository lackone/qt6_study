#include <QCoreApplication>

#include "ReadWriteIni.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    writeIniFile();

    readIniFile();

    return a.exec();
}
