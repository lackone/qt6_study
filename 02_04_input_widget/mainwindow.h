#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QDateEdit>
#include <QFontComboBox>
#include <QKeySequenceEdit>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QScrollBar>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QComboBox *    combox;
    QLabel *       fontLabel;
    QFontComboBox *fontCombox;

    QLineEdit *  ledit;
    QPushButton *editbtn;
    QLabel *     editlabel;

    QPlainTextEdit *pedit;
    QRadioButton *  pradio;

    QSpinBox *spinbox;

    QDateTimeEdit *dtedit;
    QDateEdit *    dedit;
    QTimeEdit *    tedit;

    QScrollBar *vscrollbar;
    QScrollBar *hscrollbar;

    QKeySequenceEdit *qkey;

private slots:
    void comboxChange(int);
    void fontComboxChange(QFont);
    void editBtnClick();
    void pradioBtnClick();
    void spinboxChange(int);
    void qkeyChange(QKeySequence);
};
#endif  // MAINWINDOW_H
