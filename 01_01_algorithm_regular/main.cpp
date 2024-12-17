#include <QCoreApplication>
#include <QRegularExpression>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //一、【常用算法】
    int aa = 3, bb = 5;

    qDebug() << qAbs(-111);
    qDebug() << qMax(111, 222);
    qDebug() << qRound(1.425);
    qSwap(aa, bb);
    qDebug() << aa << bb;

    //二、【正则表达式】
    QRegularExpression re("^1(3|5|8)\\d{9}$");

    if (re.match("18923558899").hasMatch()) {
        qDebug() << "ok";
    } else {
        qDebug() << "err";
    }

    return a.exec();
}
