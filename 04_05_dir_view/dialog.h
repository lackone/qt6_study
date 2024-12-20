#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void fileInfoList(QFileInfoList list);

public slots:
    void showDir(QDir dir);
    void showDir();
    void clickshowdir(QListWidgetItem *item);

private:
    QLineEdit *  edit;
    QListWidget *list;
};
#endif  // DIALOG_H
