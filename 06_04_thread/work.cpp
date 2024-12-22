#include "work.h"

Work::Work(QObject *parent) : QThread{parent} {}

void Work::run()
{
    while (true) {
        for (int i = 1; i < 5; i++) {
            qDebug() << i << i << i << i;
        }
    }
}
