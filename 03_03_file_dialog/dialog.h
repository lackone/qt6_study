#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QLabel *     file_label;
    QLineEdit *  file_edit;
    QPushButton *file_btn;
    QLabel *     file_size_label;
    QLineEdit *  file_size_edit;
    QPushButton *file_size_btn;

private slots:
    void getFile();
    void getFileSize();
};
#endif  // DIALOG_H
