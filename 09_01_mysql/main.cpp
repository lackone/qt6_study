#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("root");
    db.setPort(3306);

    if (!db.open()) {
        qDebug() << "打开失败";
        return -1;
    }

    QSqlQuery query(db);

    //删除表
    QString sql = "drop table if exists test";
    if (query.exec(sql)) {
        qDebug() << "删除成功";
    } else {
        qDebug() << "删除失败";
    }

    //添加表
    sql
        = "create table if not exists test ("
          "id int primary key auto_increment,"
          "name varchar(32),"
          "sex varchar(16)"
          ") default character set utf8;";

    if (query.exec(sql)) {
        qDebug() << "添加成功";
    } else {
        qDebug() << "添加成功";
    }

    //添加数据
    for (int i = 0; i < 10; i++) {
        QString name = QString("aaa%1").arg(i);
        QString sex  = QString("男%1").arg(i);
        sql          = QString("insert into test (name, sex) values('%1', '%2')").arg(name).arg(sex);
        if (query.exec(sql)) {
            qDebug() << "添加成功";
        } else {
            qDebug() << "添加成功";
        }
    }

    db.close();

    return a.exec();
}
