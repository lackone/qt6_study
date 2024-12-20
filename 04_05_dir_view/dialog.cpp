#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    resize(500, 300);

    edit = new QLineEdit("./");
    list = new QListWidget();

    auto layout = new QGridLayout();
    layout->addWidget(edit, 0, 0);
    layout->addWidget(list, 1, 0);

    QDir        dir("./");
    QStringList strlist;
    strlist << "*";
    //获取文件夹下的文件信息列表
    QFileInfoList flist = dir.entryInfoList(strlist);

    connect(edit, SIGNAL(returnPressed()), this, SLOT(showDir()));
    connect(list, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(clickshowdir(QListWidgetItem *)));

    fileInfoList(flist);

    setLayout(layout);
}

Dialog::~Dialog() {}

//显示目录和文件对应图标
void Dialog::fileInfoList(QFileInfoList flist)
{
    list->clear();

    for (int i = 0; i < flist.size(); i++) {
        auto info = flist.at(i);
        if (info.isDir()) {
            QIcon            ico("../../dir.jpg");
            QString          filename = info.fileName();
            QListWidgetItem *item     = new QListWidgetItem(ico, filename);
            list->addItem(item);
        } else {
            QIcon            ico("../../file.jpg");
            QString          filename = info.fileName();
            QListWidgetItem *item     = new QListWidgetItem(ico, filename);
            list->addItem(item);
        }
    }
}

void Dialog::showDir()
{
    QDir        dir(edit->text());
    QStringList strlist;
    strlist << "*";

    QFileInfoList flist = dir.entryInfoList(strlist, QDir::AllEntries, QDir::DirsFirst);

    fileInfoList(flist);
}

void Dialog::showDir(QDir dir)
{
    qDebug() << dir;
    QStringList strlist;
    strlist << "*";

    QFileInfoList flist = dir.entryInfoList(strlist, QDir::AllEntries, QDir::DirsFirst);

    fileInfoList(flist);
}

void Dialog::clickshowdir(QListWidgetItem *item)
{
    QDir    dir;
    QString path = item->text();
    qDebug() << path;
    dir.setPath(edit->text());
    dir.cd(path);

    edit->setText(dir.absolutePath());

    showDir(dir);
}
