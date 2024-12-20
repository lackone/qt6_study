#include "dialog.h"

#include <QFileDialog>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    path_label  = new QLabel("文件路径");
    size_label  = new QLabel("文件大小");
    ctime_label = new QLabel("创建时间");
    mtime_label = new QLabel("修改时间");
    atime_label = new QLabel("访问时间");
    attr_label  = new QLabel("文件属性");

    path_edit  = new QLineEdit();
    size_edit  = new QLineEdit();
    ctime_edit = new QLineEdit();
    mtime_edit = new QLineEdit();
    atime_edit = new QLineEdit();

    open_btn = new QPushButton("打开文件...");

    get_attr_btn = new QPushButton("获取文件属性");

    file_chk  = new QCheckBox("文件");
    hide_chk  = new QCheckBox("隐藏");
    read_chk  = new QCheckBox("只读");
    write_chk = new QCheckBox("只写");
    run_chk   = new QCheckBox("执行");

    auto layout = new QGridLayout();

    layout->addWidget(path_label, 0, 0);
    layout->addWidget(path_edit, 0, 1);
    layout->addWidget(open_btn, 0, 2);

    layout->addWidget(size_label, 1, 0);
    layout->addWidget(size_edit, 1, 1, 1, 2);

    layout->addWidget(ctime_label, 2, 0);
    layout->addWidget(ctime_edit, 2, 1, 1, 2);

    layout->addWidget(mtime_label, 3, 0);
    layout->addWidget(mtime_edit, 3, 1, 1, 2);

    layout->addWidget(atime_label, 4, 0);
    layout->addWidget(atime_edit, 4, 1, 1, 2);

    layout->addWidget(attr_label, 5, 0, 1, 3);

    auto hlayout = new QHBoxLayout();
    hlayout->addWidget(file_chk);
    hlayout->addWidget(hide_chk);
    hlayout->addWidget(read_chk);
    hlayout->addWidget(write_chk);
    hlayout->addWidget(run_chk);

    layout->addLayout(hlayout, 6, 0, 1, 3);

    layout->addWidget(get_attr_btn, 7, 0, 1, 3);

    connect(open_btn, SIGNAL(clicked(bool)), this, SLOT(selFile()));
    connect(get_attr_btn, SIGNAL(clicked(bool)), this, SLOT(getFileAttr()));

    setLayout(layout);
}

Dialog::~Dialog() {}

void Dialog::selFile()
{
    auto file = QFileDialog::getOpenFileName(this, "选择文件", "./", "All(*)");

    if (!file.isEmpty()) {
        path_edit->setText(file);
    }
}

void Dialog::getFileAttr()
{
    QFileInfo info(path_edit->text());

    size_edit->setText(QString::number(info.size()));

    ctime_edit->setText(info.birthTime().toString("yyyy-MM-dd hh:mm:ss"));

    mtime_edit->setText(info.lastModified().toString("yyyy-MM-dd hh:mm:ss"));

    atime_edit->setText(info.lastRead().toString("yyyy-MM-dd hh:mm:ss"));

    if (info.isFile()) {
        file_chk->setChecked(true);
    } else {
        file_chk->setChecked(false);
    }
    if (info.isHidden()) {
        hide_chk->setChecked(true);
    } else {
        hide_chk->setChecked(false);
    }
    if (info.isReadable()) {
        read_chk->setChecked(true);
    } else {
        read_chk->setChecked(false);
    }
    if (info.isWritable()) {
        write_chk->setChecked(true);
    } else {
        write_chk->setChecked(false);
    }
    if (info.isExecutable()) {
        run_chk->setChecked(true);
    } else {
        run_chk->setChecked(false);
    }
}
