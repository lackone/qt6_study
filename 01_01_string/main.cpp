#include <QCoreApplication>  //QT提供的一个事件循环
#include <QDateTime>
#include <QDebug>  //调试输出

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QString 提供一个二元的“+”操作符
    QString str1 = "hello,world";
    str1         = str1 + "!!!";

    qDebug() << str1;
    qDebug() << qPrintable(str1);  //去掉双引号

    // QString::append()函数具备与“+=”操作符同样的功能
    QString str2 = "aaa";
    str2 += "bbb";
    qDebug() << str2;

    // 组合字符串 QString::asprintf()
    QString str3;
    str3 = str3.asprintf("%s %d", "test", 123);
    qDebug() << str3;

    // 字符串组合方式 QString::arg()函数
    QString str4;
    str4 = QString("%1 aaa %2").arg("ccc").arg(111);
    qDebug() << str4;

    // 函数 QString::startsWith()判断一个字符串是否以某个字符串开头
    QString str5("aabbcc");

    qDebug() << str5.startsWith("aa");
    qDebug() << str5.endsWith("cc");

    //函数 QString::contains()判断一个指定的字符串是否出现过
    qDebug() << str5.contains("bb");

    // QString::toInt() 函 数 将 字 符 串 转 换 为 整 型 数 值
    QString str6("123");
    bool    isok;
    qDebug() << str6.toInt();
    qDebug() << str6.toInt(&isok, 16);

    // QString::compare()函数对两个字符串进行比较。
    QString str7("aaa");
    QString str8("AAA");
    qDebug() << str7.compare(str8, Qt::CaseInsensitive);  //大小写不敏感
    qDebug() << str7.compare(str8);

    // Qt 将 QString 转换成 ASCII 码
    QString str9("abc");

    QByteArray arr = str9.toLatin1();
    for (int i = 0; i < arr.size(); i++) {
        qDebug() << (int)arr.at(i);
    }

    QByteArray arr2 = str9.toUtf8();
    for (int i = 0; i < arr2.size(); i++) {
        qDebug() << (int)arr2.at(i);
    }

    QDateTime dt;
    qDebug() << dt.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    QByteArray ba1("aabbcc");

    qDebug() << ba1.toLower();

    qDebug() << ba1.toUpper();

    return a.exec();
}
