#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H

#include <QMediaPlayer>
#include <QMouseEvent>
#include <QObject>
#include <QVideoWidget>
#include <QWidget>

class MyVideoWidget : public QVideoWidget
{
    Q_OBJECT
public:
    MyVideoWidget(QWidget *parent = nullptr);

    void setMediaPlayer(QMediaPlayer *player);

private:
    QMediaPlayer *player;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif  // MYVIDEOWIDGET_H
