#include "myvideowidget.h"

MyVideoWidget::MyVideoWidget(QWidget *parent) : QVideoWidget(parent) {}

void MyVideoWidget::setMediaPlayer(QMediaPlayer *p) { player = p; }

//鼠标按键，控制播放和暂停
void MyVideoWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (player->playbackState() == QMediaPlayer::PlayingState) {
            player->pause();
        } else {
            player->play();
        }
    }

    QVideoWidget::mousePressEvent(event);
}

//键盘按键，ESC退出播放
void MyVideoWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape && (isFullScreen())) {
        setFullScreen(false);
        event->accept();
    }

    QVideoWidget::keyPressEvent(event);
}
