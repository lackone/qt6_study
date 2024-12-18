#include "mainwindow.h"

#include <QDir>
#include <QGridLayout>
#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(500, 300);
    setWindowTitle("input widget");

    auto wid = new QWidget(this);
    setCentralWidget(wid);

    auto layout = new QGridLayout();

    //编辑组合框
    combox = new QComboBox(wid);
    // combox->setGeometry(10, 10, 120, 30);
    combox->setMinimumHeight(30);
    combox->addItem("aaa", QVariant("111"));
    combox->addItem("bbb", QVariant("222"));
    combox->addItem("ccc", QVariant("333"));
    combox->addItem("ddd", QVariant("444"));
    layout->addWidget(combox, 0, 0);

    connect(combox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboxChange(int)));

    //字体组合框
    auto wid2  = new QWidget(this);
    auto vbox2 = new QVBoxLayout(this);
    fontLabel  = new QLabel(wid2);
    fontLabel->setText("hello,world");
    vbox2->addWidget(fontLabel);
    fontCombox = new QFontComboBox(wid2);
    fontCombox->setMinimumHeight(30);
    vbox2->addWidget(fontCombox);
    wid2->setLayout(vbox2);
    layout->addWidget(wid2, 0, 1);

    connect(fontCombox, SIGNAL(currentFontChanged(QFont)), this, SLOT(fontComboxChange(QFont)));

    //行编辑框
    auto wid3  = new QWidget(this);
    auto vbox3 = new QVBoxLayout(this);
    ledit      = new QLineEdit(wid3);
    editbtn    = new QPushButton(wid3);
    editbtn->setText("设置文本");
    editlabel = new QLabel(wid3);
    editlabel->setText("我是tttt");
    editlabel->setMinimumHeight(30);
    vbox3->addWidget(ledit);
    vbox3->addWidget(editbtn);
    vbox3->addWidget(editlabel);
    wid3->setLayout(vbox3);
    layout->addWidget(wid3, 1, 0);

    connect(editbtn, SIGNAL(clicked()), this, SLOT(editBtnClick()));

    //文本编辑框

    //多行文本编辑器
    auto wid4  = new QWidget(this);
    auto vbox4 = new QVBoxLayout(this);
    pedit      = new QPlainTextEdit(wid4);
    pradio     = new QRadioButton("只读", wid4);
    vbox4->addWidget(pedit);
    vbox4->addWidget(pradio);
    wid4->setLayout(vbox4);
    layout->addWidget(wid4, 1, 1);

    //设置当前目录
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QFile fe("moc_mainwindow.cpp");
    fe.open(QFile::ReadOnly | QFile::Text);
    QTextStream tstr(&fe);
    pedit->insertPlainText(tstr.readAll());

    connect(pradio, SIGNAL(clicked(bool)), this, SLOT(pradioBtnClick()));

    //整数旋转框
    spinbox = new QSpinBox(this);
    spinbox->setValue(100);
    spinbox->setRange(1, 100);  //范围
    spinbox->setSingleStep(2);  //步长
    spinbox->setSuffix("%");    //后缀

    layout->addWidget(spinbox, 2, 0);

    connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(spinboxChange(int)));

    //时间
    auto wid5  = new QWidget(this);
    auto vbox5 = new QVBoxLayout(this);
    dtedit     = new QDateTimeEdit(QDateTime::currentDateTime(), wid5);
    tedit      = new QTimeEdit(QTime::currentTime(), wid5);
    dedit      = new QDateEdit(QDate::currentDate(), wid5);
    vbox5->addWidget(dtedit);
    vbox5->addWidget(tedit);
    vbox5->addWidget(dedit);
    wid5->setLayout(vbox5);
    layout->addWidget(wid5, 2, 1);

    //水平和垂直滚动条
    vscrollbar = new QScrollBar(Qt::Vertical, wid);
    vscrollbar->setGeometry(0, 0, 30, 300);
    hscrollbar = new QScrollBar(Qt::Horizontal, wid);
    hscrollbar->setGeometry(0, 300, 600, 30);

    //水平和垂直滑动条

    //快捷键输入控件
    qkey = new QKeySequenceEdit();
    qkey->setMaximumSequenceLength(1);
    layout->addWidget(qkey, 3, 0);

    connect(qkey, SIGNAL(keySequenceChanged(QKeySequence)), this, SLOT(qkeyChange(QKeySequence)));

    wid->setLayout(layout);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::comboxChange(int index) { QMessageBox::information(this, "", combox->itemText(index) + " data:" + combox->itemData(index).toString()); }

void MainWindow::fontComboxChange(QFont font) { fontLabel->setFont(font); }

void MainWindow::editBtnClick() { editlabel->setText(ledit->text()); }

void MainWindow::pradioBtnClick()
{
    if (pradio->isChecked()) {
        pedit->setReadOnly(true);
    } else {
        pedit->setReadOnly(false);
    }
}

void MainWindow::spinboxChange(int c)
{
    double d = (double)c / 100;
    setWindowOpacity(d);
}

void MainWindow::qkeyChange(QKeySequence key)
{
    qDebug() << key.toString();

    if (key == QKeySequence("Ctrl+X")) {
        close();
    }
}
