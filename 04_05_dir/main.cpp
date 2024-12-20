#include <QCoreApplication>
#include <QDir>

qint64 getDirFileSize(const QString &path)
{
    QDir   dir(path);
    qint64 size = 0;

    foreach (QFileInfo info, dir.entryInfoList(QDir::Files)) {
        size += info.size();
    }

    foreach (QString d, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        size += getDirFileSize(path + QDir::separator() + d);
    }

    char   unit = 'B';
    double tmp  = size;
    if (tmp > 1024) {
        tmp  = tmp / 1024;
        unit = 'K';
        if (tmp > 1024) {
            unit = 'M';
            tmp  = tmp / 1024;
            if (tmp > 1024) {
                unit = 'G';
                tmp  = tmp / 1024;
                if (tmp > 1024) {
                    unit = 'T';
                    tmp  = tmp / 1024;
                }
            }
        }
    }
    qDebug() << path << "大小" << tmp << unit;

    return size;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto cur = QDir::currentPath();
    qDebug() << cur;

    //调用函数，算出目录占用空间大小
    getDirFileSize(cur);

    return a.exec();
}
