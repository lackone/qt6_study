#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //���������룬�༭-��ѡ�����-��GB18030-�������뱣��
    cout << "��ã�ѧϰQT" << endl;

    return a.exec();
}
