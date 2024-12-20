#include <QCoreApplication>
#include <QFile>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    qint32 qnum[] = {1, 2, 3};

    //以二进制方式写入到文件中
    QByteArray arr;
    arr.resize(sizeof(qnum));

    for (int i = 0; i < 3; i++) {
        memcpy(arr.data() + i * sizeof(qint32), &qnum[i], sizeof(qint32));
    }

    QFile re("./1.bin");
    re.open(QFile::WriteOnly);
    re.write(arr);
    re.close();

    QFile re2("./1.bin");
    re2.open(QFile::ReadOnly);

    QByteArray arr2 = re2.readAll();
    qDebug() << arr2;

    re2.close();

    //读取二进制数据
    char* data = arr2.data();

    while (*data) {
        qDebug() << *(qint32*)data;
        data += sizeof(qint32);
    }

    return a.exec();
}
