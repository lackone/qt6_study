#ifndef MODELEXTEND_H
#define MODELEXTEND_H

#include <QAbstractTableModel>

class ModelExtend : public QAbstractTableModel
{
public:
    explicit ModelExtend(QObject *parent = nullptr);

private:
    QVector<int> no_index;
    QVector<int> name_index;

    QMap<int, QString> mno;
    QMap<int, QString> mname;

    QStringList title;  //标题

    void modelfunc();

    // QAbstractItemModel interface
public:
    int      rowCount(const QModelIndex &parent) const;
    int      columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif  // MODELEXTEND_H
