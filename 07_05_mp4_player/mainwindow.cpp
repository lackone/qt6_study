#include "mainwindow.h"

#include <QFileDialog>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer();

    player->setVideoOutput(ui->graphicsView);  //设置显示组件

    ui->graphicsView->setMediaPlayer(player);  //设置显示组件关联播放器

    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(drttimechg(qint64)));

    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(psttimechg(qint64)));

    connect(player, SIGNAL(playbackStateChanged(QMediaPlayer::PlaybackState)), this, SLOT(statechg(QMediaPlayer::PlaybackState)));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_open_btn_clicked()
{
    auto cur = QDir::currentPath();

    auto file = QFileDialog::getOpenFileName(this, "选择视频文件", cur, "所有文件(*.*);;mp4文件(*.mp4);;");

    QFileInfo fi(file);
    ui->name_label->setText(fi.fileName());

    player->setSource(QUrl::fromLocalFile(file));

    audio = new QAudioOutput();
    player->setAudioOutput(audio);

    player->play();
}

void MainWindow::on_play_btn_clicked() { player->play(); }

void MainWindow::on_pause_btn_clicked() { player->pause(); }

void MainWindow::on_stop_btn_clicked() { player->stop(); }

void MainWindow::on_sound_btn_clicked()
{
    bool muted = audio->isMuted();

    audio->setMuted(!muted);

    if (muted) {
        ui->sound_btn->setIcon(QIcon(":/images/volumn.bmp"));
    } else {
        ui->sound_btn->setIcon(QIcon(":/images/mute.bmp"));
    }
}

void MainWindow::on_sound_slider_sliderMoved(int position)
{
    float volume = static_cast<float>(position) / 100.0f;
    audio->setVolume(volume);
}

void MainWindow::on_time_slider_sliderMoved(int position) { player->setPosition(position); }

//状态改变
void MainWindow::statechg(QMediaPlayer::PlaybackState state)
{
    ui->play_btn->setEnabled(!(state == QMediaPlayer::PlayingState));
    ui->pause_btn->setEnabled(state == QMediaPlayer::PlayingState);
    ui->stop_btn->setEnabled(state == QMediaPlayer::PlayingState);
}

//视频文件时间长度
void MainWindow::drttimechg(qint64 drt)
{
    ui->time_slider->setMaximum(drt);

    int sec = drt / 1000;
    int min = sec / 60;
    sec     = sec % 60;

    drtTime = QString::asprintf("%d:%d", min, sec);

    ui->time_label->setText(pstTime + "|" + drtTime);
}

//视频播放当前位置时间，更新变化
void MainWindow::psttimechg(qint64 pst)
{
    if (ui->time_slider->isSliderDown()) {
        return;  //如果手动滑动条，直接退出
    }

    ui->time_slider->setSliderPosition(pst);

    int sec = pst / 1000;
    int min = sec / 60;
    sec     = sec % 60;

    pstTime = QString::asprintf("%d:%d", min, sec);

    ui->time_label->setText(pstTime + "|" + drtTime);
}
