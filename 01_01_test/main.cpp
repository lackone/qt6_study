#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //如果输出乱码，编辑-》选择编码-》GB18030-》按编码保存
    cout << "你好，学习QT" << endl;

    return a.exec();
}
