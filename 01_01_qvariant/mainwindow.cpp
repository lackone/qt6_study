#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    //可以存放任意类型
    QVariant var1(333);

    qDebug() << var1.toInt();

    QVariant var2("hello,world");

    qDebug() << var2.toString();

    QMap<QString, QVariant> map;
    map["int"]    = 123;
    map["double"] = 3.14;
    map["string"] = "test";
    map["color"]  = QColor(255, 255, 0);

    qDebug() << map;

    //转化函数
    qDebug() << map["int"].toInt();
    qDebug() << map["double"].toDouble();
    qDebug() << map["string"].toString();
    qDebug() << map["color"].value<QColor>();

    //将列表存储在一个 QVariant 变量
    QStringList qsl;
    qsl << "aa"
        << "bb"
        << "cc"
        << "dd";

    QVariant qvsl(qsl);
    if (qvsl.typeId() == QMetaType::QStringList) {
        auto sl = qvsl.toStringList();
        for (int i = 0; i < sl.size(); i++) {
            qDebug() << sl.at(i);
        }
    }

    // 结构体类型和 QVariant 类配合使用
    Person p;
    p.name  = "abc";
    p.no    = 101;
    p.score = 99.9;

    // 使用静态方法保存数据
    QVariant qobj = QVariant::fromValue(p);
    // 判断是否可以转换操作
    if (qobj.canConvert<Person>()) {
        auto pp  = qobj.value<Person>();
        auto pp2 = qvariant_cast<Person>(qobj);
        qDebug() << pp.name << pp.no << pp.score;
    }
}

MainWindow::~MainWindow() {}
