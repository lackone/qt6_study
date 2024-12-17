#include <QCoreApplication>
#include <QLinkedList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QList 类
    QList<int> list;
    for (int i = 0; i < 10; i++) {
        list.insert(list.end(), i);
    }

    //遍历
    for (auto iter = list.begin(); iter != list.end(); iter++) {
        qDebug() << *iter;
    }

    // 向 qlist 添加元素
    list.append(222);
    list.append(333);

    qDebug() << list.at(2);

    // 查询 qlist 当中元素
    qDebug() << list.contains(9);

    // 修改 qlist 列表里面的元素值
    list.replace(0, 99);
    qDebug() << list;

    // 删除元素
    list.removeAt(2);
    qDebug() << list;

    list.removeFirst();
    qDebug() << list;

    // QLinkedList 类
    QLinkedList<QString> ll;

    for (int i = 1; i <= 12; i++) {
        ll << QString("month%1").arg(i);
    }

    //只读迭代器
    for (auto iter = ll.constBegin(); iter != ll.constEnd(); iter++) {
        qDebug() << *iter;
    }

    //读写迭代器
    for (auto iter = ll.begin(); iter != ll.end(); iter++) {
        qDebug() << *iter;
    }

    return a.exec();
}
