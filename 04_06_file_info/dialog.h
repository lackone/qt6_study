#ifndef DIALOG_H
#define DIALOG_H

#include <QCheckBox>
#include <QDateTime>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QLabel *path_label;
    QLabel *size_label;
    QLabel *ctime_label;
    QLabel *mtime_label;
    QLabel *atime_label;
    QLabel *attr_label;

    QLineEdit *path_edit;
    QLineEdit *size_edit;
    QLineEdit *ctime_edit;
    QLineEdit *mtime_edit;
    QLineEdit *atime_edit;

    QPushButton *open_btn;

    QPushButton *get_attr_btn;

    QCheckBox *file_chk;
    QCheckBox *hide_chk;
    QCheckBox *read_chk;
    QCheckBox *write_chk;
    QCheckBox *run_chk;

private slots:
    void selFile();
    void getFileAttr();
};
#endif  // DIALOG_H
