#include <QCoreApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("./1.txt");

    if (!file.open(QFile::WriteOnly)) {
        qDebug() << "打开失败";
    }

    QTextStream stream(&file);

    stream << "我是中国人"
           << "哈哈~~~~~~";

    file.close();

    //读取
    QFile f2("./1.txt");
    f2.open(QFile::ReadOnly);
    QTextStream stream2(&f2);

    while (!stream2.atEnd()) {
        QString str;
        stream2 >> str;
        qDebug() << str;
    }

    f2.close();

    return a.exec();
}
