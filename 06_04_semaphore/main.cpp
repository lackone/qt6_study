#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <QTime>

const int data_size = 100;
const int buf_size  = 1;

QSemaphore free_space(buf_size);
QSemaphore use_space(0);

class producer : public QThread
{
protected:
    void run()
    {
        for (int i = 0; i < data_size; i++) {
            free_space.acquire();  //获取资源

            qDebug() << i << "producer--->";

            use_space.release();  //释放资源
        }
    }
};

class consumer : public QThread
{
protected:
    void run()
    {
        for (int i = 0; i < data_size; i++) {
            use_space.acquire();  //获取资源

            qDebug() << i << "<----consumer";

            free_space.release();  //释放资源
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    producer p;
    consumer c;

    p.start();
    c.start();

    p.wait();
    c.wait();

    return a.exec();
}
