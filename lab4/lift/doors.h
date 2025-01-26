#ifndef __DOORS_H__
#define __DOORS_H__

#include <QObject>
#include <QTimer>
#include <QDebug>

#include "settings.h"

class Doors : public QObject {
    Q_OBJECT
    enum state {CLOSED, OPENING, OPENED, CLOSING};

public:
    Doors(void);
    ~Doors(void) = default;

signals:
    void closed(void);

private slots:
    void closing(void);
    void opening(void);

public slots:
    void close(void);
    void open(void);

private:
    state _state;
    QTimer _openedTimer;
    QTimer _openingTimer;
    QTimer _closingTimer;
};

#endif // __DOORS_H__