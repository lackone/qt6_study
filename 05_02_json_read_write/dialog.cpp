#include "dialog.h"

#include <QFile>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) { ui->setupUi(this); }

Dialog::~Dialog() { delete ui; }

void Dialog::on_pushButton_clicked()
{
    // 1、写入json

    QJsonObject obj;

    obj.insert("ip", "192.168.1.1");
    obj.insert("port", "3306");
    obj.insert("username", "root");
    obj.insert("password", "123456");

    QJsonObject res;
    res.insert("code", "1");
    res.insert("msg", "成功");
    res.insert("data", obj);

    // 2、创建json文档
    QJsonDocument doc;
    doc.setObject(res);

    // 3、创建文件
    QFile f("./test.json");
    if (f.open(QFile::WriteOnly)) {
        qDebug() << doc.toJson();
        f.write(doc.toJson());
    }

    f.close();
}

void Dialog::on_pushButton_2_clicked()
{
    QFile f("./test.json");

    QByteArray data;
    if (f.open(QFile::ReadOnly)) {
        data = f.readAll();
        f.close();
    }

    QJsonParseError err;
    QJsonDocument   doc = QJsonDocument::fromJson(data, &err);

    if (!doc.isEmpty() && err.error == QJsonParseError::NoError) {
        //转换JSON对象
        QJsonObject obj = doc.object();

        auto code = obj.value("code");
        auto data = obj.value("data");
        auto msg  = obj.value("msg");

        qDebug() << code;
        qDebug() << data;
        qDebug() << msg;

        if (code.isUndefined() || code.toString().toInt() != 1 || data.isUndefined() || !data.isObject()) {
            qDebug() << code.isUndefined();
            qDebug() << code.toInt();
            qDebug() << code.toString().toInt();
            qDebug() << data.isUndefined();
            qDebug() << !data.isObject();

            qDebug() << "json转换错误1";
            return;
        }

        auto info = data.toObject();

        auto ip       = info.value("ip");
        auto port     = info.value("port");
        auto username = info.value("username");
        auto password = info.value("password");

        //检测数据是否正确
        if (ip.isUndefined() || port.isUndefined() || username.isUndefined() || password.isUndefined()) {
            qDebug() << "json转换错误2";
            return;
        }

        qDebug() << ip.toString();
        qDebug() << port.toString();
        qDebug() << username.toString();
        qDebug() << password.toString();
    }
}
