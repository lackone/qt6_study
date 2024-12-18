#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("员工信息");
    resize(500, 500);

    //左边控件
    glayout = new QGridLayout();

    user_no        = new QLabel("编号");
    user_no_edit   = new QLineEdit();
    user_name      = new QLabel("姓名");
    user_name_edit = new QLineEdit();
    user_sex       = new QLabel("性别");
    user_sex_box   = new QComboBox();
    user_sex_box->addItem("男");
    user_sex_box->addItem("女");
    user_dept     = new QLabel("部门");
    user_dept_box = new QComboBox();
    user_dept_box->addItem("行政");
    user_dept_box->addItem("人事");
    user_dept_box->addItem("财务");
    user_age      = new QLabel("年龄");
    user_age_edit = new QTextEdit();

    glayout->addWidget(user_no, 0, 0);
    glayout->addWidget(user_name, 1, 0);
    glayout->addWidget(user_sex, 2, 0);
    glayout->addWidget(user_dept, 3, 0);
    glayout->addWidget(user_age, 4, 0);
    glayout->addWidget(user_no_edit, 0, 1);
    glayout->addWidget(user_name_edit, 1, 1);
    glayout->addWidget(user_sex_box, 2, 1);
    glayout->addWidget(user_dept_box, 3, 1);
    glayout->addWidget(user_age_edit, 4, 1);

    glayout->setColumnStretch(0, 1);
    glayout->setColumnStretch(1, 3);

    //右边控件
    rvboxlayout   = new QVBoxLayout();
    user_info     = new QLabel("简历：");
    user_info_txt = new QTextEdit();
    rvboxlayout->addWidget(user_info);
    rvboxlayout->addWidget(user_info_txt);

    //右下
    bhboxlayout = new QHBoxLayout();
    okbtn       = new QPushButton("确定");
    cancelbtn   = new QPushButton("取消");
    //可伸缩空间
    bhboxlayout->addStretch();
    bhboxlayout->addWidget(okbtn);
    bhboxlayout->addWidget(cancelbtn);

    QGridLayout *mlayout = new QGridLayout(this);
    mlayout->addLayout(glayout, 0, 0);
    mlayout->addLayout(rvboxlayout, 0, 1);
    mlayout->addLayout(bhboxlayout, 1, 0, 1, 2);

    // mlayout->setSizeConstraint(QLayout::SetFixedSize);

    setLayout(mlayout);
}

Dialog::~Dialog() {}
