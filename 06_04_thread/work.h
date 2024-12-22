#ifndef WORK_H
#define WORK_H

#include <QDebug>
#include <QThread>

class Work : public QThread
{
    Q_OBJECT
public:
    explicit Work(QObject *parent = nullptr);

    // QThread interface
protected:
    void run();
};

#endif  // WORK_H
