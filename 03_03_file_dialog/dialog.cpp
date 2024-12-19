#include "dialog.h"

#include <QFileDialog>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("file dialog 对话框");

    // 1、创建控件
    file_label      = new QLabel("选择文件：");
    file_edit       = new QLineEdit();
    file_btn        = new QPushButton("文件...");
    file_size_label = new QLabel("文件大小：");
    file_size_edit  = new QLineEdit();
    file_size_btn   = new QPushButton("获取文件大小");

    // 2、布局
    auto layout = new QGridLayout();

    auto h1 = new QHBoxLayout();
    h1->addWidget(file_label);
    h1->addWidget(file_edit);
    h1->addWidget(file_btn);
    auto h2 = new QHBoxLayout();
    h2->addWidget(file_size_label);
    h2->addWidget(file_size_edit);
    auto h3 = new QVBoxLayout();
    h3->addWidget(file_size_btn);

    layout->addLayout(h1, 0, 0);
    layout->addLayout(h2, 1, 0);
    layout->addLayout(h3, 2, 0);

    connect(file_btn, SIGNAL(clicked()), this, SLOT(getFile()));

    connect(file_size_btn, SIGNAL(clicked()), this, SLOT(getFileSize()));

    setLayout(layout);
}

Dialog::~Dialog() {}

void Dialog::getFile()
{
    auto file = QFileDialog::getOpenFileName(this, "选择文件", "./", "Files(*)");
    if (!file.isEmpty()) {
        file_edit->setText(file);
    }
}

void Dialog::getFileSize()
{
    QFileInfo fi(file_edit->text());

    file_size_edit->setText(QString("%1").arg(fi.size()));
}
