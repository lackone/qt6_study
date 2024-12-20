#include "modelextend.h"

ModelExtend::ModelExtend(QObject *parent) : QAbstractTableModel{parent}
{
    mno[0] = "001";
    mno[1] = "002";
    mno[2] = "003";

    mname[0] = "张三";
    mname[1] = "李四";
    mname[2] = "王五";

    modelfunc();
}

void ModelExtend::modelfunc()
{
    title << "员工编号"
          << "员工姓名";

    no_index << 0 << 1 << 2;
    name_index << 0 << 1 << 2;
}

//行
int ModelExtend::rowCount(const QModelIndex &parent) const { return no_index.size(); }

//列
int ModelExtend::columnCount(const QModelIndex &parent) const { return 2; }

//显示数据
QVariant ModelExtend::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        qDebug() << "row" << index.row() << "col" << index.column();
        switch (index.column()) {
            case 0:
                return mno[no_index[index.row()]];
                break;
            case 1:
                return mname[name_index[index.row()]];
                break;
        }
    }

    return QVariant();
}

//表头数据
QVariant ModelExtend::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return title[section];
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}
