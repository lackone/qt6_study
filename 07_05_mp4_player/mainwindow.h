#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAudioOutput>
#include <QDir>
#include <QMainWindow>
#include <QMediaPlayer>

#include "myvideowidget.h"

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

private slots:
    void on_open_btn_clicked();

    void on_play_btn_clicked();

    void on_pause_btn_clicked();

    void on_stop_btn_clicked();

    void on_sound_btn_clicked();

    void on_sound_slider_sliderMoved(int position);

    void on_time_slider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    QMediaPlayer *player;
    QAudioOutput *audio;
    QString       drtTime;  //总时间
    QString       pstTime;  //当前播放时间

private slots:
    void statechg(QMediaPlayer::PlaybackState);
    void drttimechg(qint64 drt);
    void psttimechg(qint64 pst);
};
#endif  // MAINWINDOW_H
