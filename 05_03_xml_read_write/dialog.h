#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QLabel *no_label;
    QLabel *name_label;
    QLabel *sex_label;
    QLabel *edu_label;
    QLabel *dept_label;
    QLabel *salary_label;

    QLineEdit *no_edit;
    QLineEdit *name_edit;
    QLineEdit *sex_edit;
    QLineEdit *edu_edit;
    QLineEdit *dept_edit;
    QLineEdit *salary_edit;

    QLineEdit *no_edit2;
    QLineEdit *name_edit2;
    QLineEdit *sex_edit2;
    QLineEdit *edu_edit2;
    QLineEdit *dept_edit2;
    QLineEdit *salary_edit2;

    QPushButton *w_btn;
    QPushButton *r_btn;

private slots:
    void wXMl();
    void rXMl();
};
#endif  // DIALOG_H
