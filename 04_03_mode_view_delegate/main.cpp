#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QApplication>
//#include <QDirModel>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QListView>
#include <QSplitter>
#include <QTableView>
#include <QTreeView>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    QFileSystemModel *fsmodel = new QFileSystemModel();
    fsmodel->setRootPath(QDir::rootPath());  // 设置要显示的根路径

    QTreeView  tree;
    QListView  list;
    QTableView table;

    tree.setModel(fsmodel);
    list.setModel(fsmodel);
    table.setModel(fsmodel);

    tree.setSelectionMode(QAbstractItemView::MultiSelection);
    list.setSelectionModel(tree.selectionModel());
    table.setSelectionModel(tree.selectionModel());

    QSplitter *split = new QSplitter();
    split->addWidget(&tree);
    split->addWidget(&list);
    split->addWidget(&table);

    QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &list, SLOT(setRootIndex(QModelIndex)));
    QObject::connect(&tree, SIGNAL(doubleClicked(QModelIndex)), &table, SLOT(setRootIndex(QModelIndex)));

    split->show();

    return a.exec();
}
