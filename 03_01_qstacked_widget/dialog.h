#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QListWidget>
#include <QStackedWidget>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void listclick(QModelIndex);

private:
    QStackedWidget *stack;
    QListWidget *   list;
    QLabel *        label1;
    QLabel *        label2;
    QLabel *        label3;
};
#endif  // DIALOG_H
