#include "mainwindow.h"

#include <QAudioOutput>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player   = new QMediaPlayer();
    playlist = new QList<QUrl>();

    audio = new QAudioOutput();
    player->setAudioOutput(audio);

    //状态变化
    connect(player, SIGNAL(playbackStateChanged(QMediaPlayer::PlaybackState)), this, SLOT(statechg(QMediaPlayer::PlaybackState)));

    //当前播放位置
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(pstchg(qint64)));

    //播放时长
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(drtchg(qint64)));

    //播放列表
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(playlistchg(int)));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::statechg(QMediaPlayer::PlaybackState state)
{
    ui->play_btn->setEnabled(!(state == QMediaPlayer::PlayingState));
    ui->pause_btn->setEnabled(state == QMediaPlayer::PlayingState);
    ui->stop_btn->setEnabled(state == QMediaPlayer::PlayingState);
}

void MainWindow::playlistchg(int pos)
{
    ui->listWidget->setCurrentRow(pos);

    auto item = ui->listWidget->currentItem();
    if (item) {
        ui->name_label->setText(item->text());
    }
}

void MainWindow::drtchg(qint64 drt)
{
    ui->time_slider->setMaximum(drt);

    int sec = drt / 1000;
    int min = sec / 60;
    sec     = sec % 60;  //余数为秒

    drtTime = QString::asprintf("%d:%d", min, sec);

    ui->time_label->setText(pstTime + "|" + drtTime);
}

void MainWindow::pstchg(qint64 pos)
{
    if (ui->time_slider->isSliderDown()) {
        return;
    }

    ui->time_slider->setSliderPosition(pos);

    int sec = pos / 1000;
    int min = sec / 60;
    sec     = sec % 60;  //余数为秒

    pstTime = QString::asprintf("%d:%d", min, sec);

    ui->time_label->setText(pstTime + "|" + drtTime);
}

void MainWindow::on_open_btn_clicked()
{
    auto cur = QDir::currentPath();

    auto file_list = QFileDialog::getOpenFileNames(this, "请选择音频文件", cur, "所有文件(*.*);;音频文件(*.mp3 *.wav *.wma);;MP3文件(*.mp3)");

    if (file_list.isEmpty()) {
        return;
    }

    for (auto &v : file_list) {
        playlist->append(QUrl::fromLocalFile(v));

        QFileInfo fi(v);
        ui->listWidget->addItem(fi.fileName());
    }

    if (player->playbackState() != QMediaPlayer::PlayingState) {
        play_cur = 0;
        ui->listWidget->setCurrentRow(0);
    }

    qDebug() << playlist->at(play_cur);
    player->setSource(playlist->at(play_cur));
    player->play();
}

void MainWindow::on_play_btn_clicked()
{
    player->setSource(playlist->at(play_cur));
    player->play();
}

void MainWindow::on_pause_btn_clicked() { player->pause(); }

void MainWindow::on_stop_btn_clicked() { player->stop(); }

void MainWindow::on_prev_btn_clicked()
{
    if (play_cur == 0) {
        play_cur = playlist->size() - 1;
    } else {
        play_cur--;
    }

    ui->listWidget->setCurrentRow(play_cur);

    player->setSource(playlist->at(play_cur));
    player->play();
}

void MainWindow::on_next_btn_clicked()
{
    if (play_cur == playlist->size() - 1) {
        play_cur = 0;
    } else {
        play_cur++;
    }

    ui->listWidget->setCurrentRow(play_cur);

    player->setSource(playlist->at(play_cur));
    player->play();
}

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

void MainWindow::on_time_slider_valueChanged(int value)
{
    // player->setPosition(value);
}

void MainWindow::on_sound_slider_valueChanged(int value)
{
    qDebug() << value;

    audio->setVolume(value);
}

void MainWindow::on_time_slider_sliderMoved(int position) { player->setPosition(position); }

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    play_cur = ui->listWidget->currentRow();
    player->setSource(playlist->at(play_cur));
    player->play();
}
