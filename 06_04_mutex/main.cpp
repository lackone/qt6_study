#include <QCoreApplication>
#include <QMutex>
#include <QThread>

// 售票类
class ticketSellers : public QObject
{
public:
    ticketSellers();
    ~ticketSellers();

public slots:
    void salefunc();  //售票

public:
    int *   tickets;  //票
    QMutex *mutex;    //锁
    QString name;     //售票员姓名
};

ticketSellers::ticketSellers() {}

ticketSellers::~ticketSellers() {}

void ticketSellers::salefunc()
{
    while ((*tickets) > 0) {
        mutex->lock();
        qDebug() << name << ":" << (*tickets)--;
        mutex->unlock();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int    tickets = 20;
    QMutex mtx;

    QThread       t1;
    ticketSellers s1;
    s1.tickets = &tickets;
    s1.mutex   = &mtx;
    s1.name    = "test1";
    //将对象移动到线程
    s1.moveToThread(&t1);

    QThread       t2;
    ticketSellers s2;
    s2.tickets = &tickets;
    s2.mutex   = &mtx;
    s2.name    = "test2";
    s2.moveToThread(&t2);

    QThread       t3;
    ticketSellers s3;
    s3.tickets = &tickets;
    s3.mutex   = &mtx;
    s3.name    = "test3";
    s3.moveToThread(&t3);

    QObject::connect(&t1, &QThread::started, &s1, &ticketSellers::salefunc);
    QObject::connect(&t2, &QThread::started, &s2, &ticketSellers::salefunc);
    QObject::connect(&t3, &QThread::started, &s3, &ticketSellers::salefunc);

    t1.start();
    t2.start();
    t3.start();

    return a.exec();
}
