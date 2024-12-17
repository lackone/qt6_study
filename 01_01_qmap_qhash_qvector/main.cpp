#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QMap类
    QMap<QString, QString> m;
    // 1、插入数据两种方式
    m["aaa"] = "111";
    m["bbb"] = "222";

    m.insert("ccc", "333");
    m.insert("ddd", "444");

    qDebug() << m;

    // 2、删除数据
    m.remove("ccc");
    qDebug() << m;

    // 3、遍历数据 (java类型的迭代)
    QMapIterator<QString, QString> iter(m);
    while (iter.hasNext()) {
        iter.next();
        qDebug() << iter.key() << iter.value();
    }

    // STL类型的迭代
    auto iter2 = m.constBegin();
    while (iter2 != m.constEnd()) {
        qDebug() << iter2.key() << iter2.value();
        iter2++;
    }

    // key 键/T 键-->来查找
    qDebug() << m.value("ddd");  //通过key找value
    qDebug() << m.key("444");    //通过value找key

    // 修改键值
    // 一个键对应一个值，再次调用 insert()函数将覆盖之前的值
    m.insert("aaa", "11111");
    qDebug() << m;

    // 查询是否包含某个键
    qDebug() << m.contains("bbb");
    qDebug() << m.contains("abc");

    // 输出所有 QMap 实例化：Key 键和 T 值
    auto keys = m.keys();
    qDebug() << keys;
    auto values = m.values();
    qDebug() << values;

    // 一个键对应多个值
    // 直接使用 QMultiMap 类来实例化一个 QMap 对象
    QMultiMap<QString, QString> mm;
    mm.insert("aaa", "111");
    mm.insert("aaa", "222");
    mm.insert("aaa", "333");
    qDebug() << mm;

    // QHash类
    QHash<QString, QString> hash;
    hash["aaa"] = "111";
    hash["bbb"] = "222";
    hash["ccc"] = "333";

    auto list = hash.keys();
    for (int i = 0; i < list.size(); i++) {
        qDebug() << list[i] << hash.value(list[i]);
    }

    //遍历
    for (auto iter = hash.begin(); iter != hash.end(); iter++) {
        qDebug() << iter.key() << iter.value();
    }

    // QVector 类
    QVector<int> vec;
    //添加
    vec << 10;
    vec << 20;
    vec << 30;
    vec.append(40);
    vec.append(50);
    vec.append(60);

    //元素个数
    qDebug() << vec.count();
    //遍历
    for (int i = 0; i < vec.size(); i++) {
        qDebug() << vec[i];
    }
    //删除
    vec.remove(1);

    qDebug() << vec;

    vec.remove(0, 2);  //从0开始，删除2个

    qDebug() << vec;

    //判断容器是否包含某个元素
    qDebug() << vec.contains(60);

    return a.exec();
}
