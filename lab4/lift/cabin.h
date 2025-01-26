#ifndef __CABIN_H__
#define __CABIN_H__

#include <QObject>
#include <QTimer>
#include <memory>
#include <QDebug>

#include "settings.h"
#include "doors.h"

class Cabin : public QObject {
    Q_OBJECT
    enum state {WAITING, MOVING, STAYING};

public:
    Cabin(void);
    ~Cabin(void) = default;

signals:
    void needTarget(void);
    void floorChanged(void);
    void arrived(void);

public slots:
    void wait(void);
    void move(void);
    void stop(void);

private:
    state _state;
    std::unique_ptr<Doors> _doors;
    QTimer _movingTimer;
};

#endif // __CABIN_H__