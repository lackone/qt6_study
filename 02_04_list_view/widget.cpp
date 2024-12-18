#include "widget.h"

#include <QMessageBox>
#include <QStringListModel>

#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("ListView");

    resize(500, 300);

    // 1、创建listview
    lview = new QListView(this);
    lview->setGeometry(0, 0, 500, 300);

    // 2、创建数据
    QStringList slist;
    slist << "蓝球"
          << "足球"
          << "电影"
          << "音乐";

    // 3、创建model
    QStringListModel *model = new QStringListModel(slist);
    // 4、设置model
    lview->setModel(model);

    connect(lview, SIGNAL(clicked(QModelIndex)), this, SLOT(listClick(QModelIndex)));
}

Widget::~Widget() { delete ui; }

void Widget::listClick(QModelIndex index) { QMessageBox::information(this, "信息", QString("%1").arg(index.data().toString())); }
