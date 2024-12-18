#ifndef DIALOG_H
#define DIALOG_H

#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    // 左边布局
    QGridLayout *glayout;
    QLabel *     user_no;
    QLineEdit *  user_no_edit;
    QLabel *     user_name;
    QLineEdit *  user_name_edit;
    QLabel *     user_sex;
    QComboBox *  user_sex_box;
    QLabel *     user_dept;
    QComboBox *  user_dept_box;
    QLabel *     user_age;
    QTextEdit *  user_age_edit;

    // 右边，水平布局
    QVBoxLayout *rvboxlayout;
    QLabel *     user_info;
    QTextEdit *  user_info_txt;

    QPushButton *okbtn;
    QPushButton *cancelbtn;
    QHBoxLayout *bhboxlayout;
};
#endif  // DIALOG_H
