#include "mainwindow.h"

#include <QApplication>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setGeometry(300, 300, 400, 300);

    toolbar = new QToolBar(this);
    toolbar->setGeometry(20, 20, 200, 90);

    //获取系统自带图标
    QStyle *sty  = QApplication::style();
    QIcon   icon = sty->standardIcon(QStyle::SP_TitleBarContextHelpButton);

    toolbtn = new QToolButton();
    toolbtn->setIcon(icon);

    toolbtn->setText("系统帮助提示");                          //显示文本
    toolbtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);  //文字在图标下

    toolbar->addWidget(toolbtn);
}

MainWindow::~MainWindow() {}
