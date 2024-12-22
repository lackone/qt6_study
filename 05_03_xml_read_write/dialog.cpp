#include "dialog.h"

#include <QDomDocument>
#include <QFile>
#include <QGridLayout>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    auto layout = new QGridLayout();

    no_label     = new QLabel("编号");
    name_label   = new QLabel("姓名");
    sex_label    = new QLabel("性别");
    edu_label    = new QLabel("学历");
    dept_label   = new QLabel("部门");
    salary_label = new QLabel("薪资");

    no_edit     = new QLineEdit();
    name_edit   = new QLineEdit();
    sex_edit    = new QLineEdit();
    edu_edit    = new QLineEdit();
    dept_edit   = new QLineEdit();
    salary_edit = new QLineEdit();

    auto hb = new QHBoxLayout();
    hb->addWidget(no_label);
    hb->addWidget(no_edit);
    layout->addLayout(hb, 0, 0);

    auto hb2 = new QHBoxLayout();
    hb2->addWidget(name_label);
    hb2->addWidget(name_edit);
    layout->addLayout(hb2, 1, 0);

    auto hb3 = new QHBoxLayout();
    hb3->addWidget(sex_label);
    hb3->addWidget(sex_edit);
    layout->addLayout(hb3, 2, 0);

    auto hb4 = new QHBoxLayout();
    hb4->addWidget(edu_label);
    hb4->addWidget(edu_edit);
    layout->addLayout(hb4, 3, 0);

    auto hb5 = new QHBoxLayout();
    hb5->addWidget(dept_label);
    hb5->addWidget(dept_edit);
    layout->addLayout(hb5, 4, 0);

    auto hb6 = new QHBoxLayout();
    hb6->addWidget(salary_label);
    hb6->addWidget(salary_edit);
    layout->addLayout(hb6, 5, 0);

    no_edit2     = new QLineEdit();
    name_edit2   = new QLineEdit();
    sex_edit2    = new QLineEdit();
    edu_edit2    = new QLineEdit();
    dept_edit2   = new QLineEdit();
    salary_edit2 = new QLineEdit();

    layout->addWidget(no_edit2, 0, 1);
    layout->addWidget(name_edit2, 1, 1);
    layout->addWidget(sex_edit2, 2, 1);
    layout->addWidget(edu_edit2, 3, 1);
    layout->addWidget(dept_edit2, 4, 1);
    layout->addWidget(salary_edit2, 5, 1);

    w_btn = new QPushButton("写入XML");
    r_btn = new QPushButton("读取XML");

    connect(w_btn, SIGNAL(clicked()), this, SLOT(wXMl()));
    connect(r_btn, SIGNAL(clicked()), this, SLOT(rXMl()));

    layout->addWidget(w_btn, 6, 0);
    layout->addWidget(r_btn, 6, 1);

    setLayout(layout);
}

Dialog::~Dialog() { delete ui; }

void Dialog::wXMl()
{
    QFile f("./test.xml");
    if (f.open(QFile::ReadWrite)) {
        QDomDocument dom;
        auto         ver = dom.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
        dom.appendChild(ver);

        auto root = dom.createElement("root");
        dom.appendChild(root);

        auto item = dom.createElement("person");

        auto node1 = dom.createElement("no");
        auto txt1  = dom.createTextNode("no");
        txt1.setData(no_edit->text());
        node1.appendChild(txt1);
        item.appendChild(node1);

        auto node2 = dom.createElement("name");
        auto txt2  = dom.createTextNode("name");
        txt2.setData(name_edit->text());
        node2.appendChild(txt2);
        item.appendChild(node2);

        auto node3 = dom.createElement("sex");
        auto txt3  = dom.createTextNode("sex");
        txt3.setData(sex_edit->text());
        node3.appendChild(txt3);
        item.appendChild(node3);

        auto node4 = dom.createElement("edu");
        auto txt4  = dom.createTextNode("edu");
        txt4.setData(edu_edit->text());
        node4.appendChild(txt4);
        item.appendChild(node4);

        auto node5 = dom.createElement("dept");
        auto txt5  = dom.createTextNode("dept");
        txt5.setData(dept_edit->text());
        node5.appendChild(txt5);
        item.appendChild(node5);

        auto node6 = dom.createElement("salary");
        auto txt6  = dom.createTextNode("salary");
        txt6.setData(salary_edit->text());
        node6.appendChild(txt6);
        item.appendChild(node6);

        root.appendChild(item);

        f.write(dom.toString().toUtf8().data());

        f.close();
    }
}

void Dialog::rXMl()
{
    QFile f("./test.xml");
    if (f.open(QFile::ReadWrite)) {
        QDomDocument dom;
        if (!dom.setContent(&f)) {
            qDebug() << "打开失败";
            return;
        }

        //读取根节点
        auto root = dom.documentElement();
        //读取第一个
        auto node = root.firstChild();

        while (!node.isNull()) {
            //所有子节点
            auto son       = node.childNodes();
            auto node_name = node.toElement().tagName();
            if (node_name == "person") {
                for (int i = 0; i < son.size(); i++) {
                    //获取子节点
                    auto son_el = son.at(i).toElement();

                    if (son_el.toElement().tagName() == "no") {
                        no_edit2->setText(son_el.text());
                    }
                    if (son_el.toElement().tagName() == "name") {
                        name_edit2->setText(son_el.text());
                    }
                    if (son_el.toElement().tagName() == "sex") {
                        sex_edit2->setText(son_el.text());
                    }
                    if (son_el.toElement().tagName() == "edu") {
                        edu_edit2->setText(son_el.text());
                    }
                    if (son_el.toElement().tagName() == "dept") {
                        dept_edit2->setText(son_el.text());
                    }
                    if (son_el.toElement().tagName() == "salary") {
                        salary_edit2->setText(son_el.text());
                    }
                }
            }

            node = node.nextSibling();  //下一节点
        }

        f.close();
    }
}
