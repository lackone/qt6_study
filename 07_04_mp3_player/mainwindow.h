#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QMediaPlayer>

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

    QAudioOutput *audio;
    QMediaPlayer *player;
    QList<QUrl> * playlist;
    int           play_cur;

    QString drtTime;  //歌长
    QString pstTime;  //播放位置

private slots:
    void statechg(QMediaPlayer::PlaybackState state);  //按钮切换状态
    void playlistchg(int pos);                         //播放列表
    void drtchg(qint64 drt);                           //歌总时长
    void pstchg(qint64 pos);                           //播放当前位置
    void on_open_btn_clicked();
    void on_play_btn_clicked();
    void on_pause_btn_clicked();
    void on_stop_btn_clicked();
    void on_prev_btn_clicked();
    void on_next_btn_clicked();
    void on_sound_btn_clicked();
    void on_time_slider_valueChanged(int value);
    void on_sound_slider_valueChanged(int value);
    void on_time_slider_sliderMoved(int position);
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
};
#endif  // MAINWINDOW_H
