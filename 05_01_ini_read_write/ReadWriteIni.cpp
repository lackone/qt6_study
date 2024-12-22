#include <QSettings>

void readIniFile()
{
    QSettings set("test.ini", QSettings::IniFormat);

    qDebug() << set.value("database/ip").toString();
    qDebug() << set.value("database/port").toString();
    qDebug() << set.value("database/username").toString();
    qDebug() << set.value("database/password").toString();

    foreach (auto key, set.allKeys()) {
        qDebug() << key << set.value(key).toString();
    }

    for (auto &key : set.allKeys()) {
        qDebug() << key << set.value(key).toString();
    }
}

void writeIniFile()
{
    //直接使用 QSettings

    QSettings set("test.ini", QSettings::IniFormat);

    //向ini写入数据

    set.setValue("database/ip", "192.168.1.1");
    set.setValue("database/port", "3306");
    set.setValue("database/username", "root");
    set.setValue("database/password", "123456");

    set.setValue("notice/version", "3.21");
    set.setValue("notice/datetime", "2024-10-11");

    // 向INI写入完成后
}
