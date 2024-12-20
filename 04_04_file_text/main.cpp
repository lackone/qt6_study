#include <QCoreApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //创建QFile对象
    QFile file("./1.txt");

    //对文件进行操作
    /*
    ReadOnly = 0x0001,
    WriteOnly = 0x0002,
    ReadWrite = ReadOnly | WriteOnly,
    Append = 0x0004,
    Truncate = 0x0008,
     */
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        qDebug() << "打开失败";
    } else {
        qDebug() << "打开成功";
    }

    file.write("中国");
    file.write("打开成功");

    file.close();

    //读取文件
    QFile re("./1.txt");
    re.open(QFile::ReadOnly);

    char *buf = new char[20];
    auto  cnt = re.readLine(buf, 20);

    qDebug() << cnt;

    while (cnt != -1 && cnt != 0) {
        qDebug() << buf;
        cnt = re.readLine(buf, 20);
    }

    re.close();

    return a.exec();
}
