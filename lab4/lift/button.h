#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <QPushButton>
#include <QDebug>

#include "settings.h"

class Button : public QPushButton {
    Q_OBJECT
    enum state {INACTIVE, ACTIVE};

public:
    Button(int floor);
    ~Button(void) = default;

signals:
    void call(int);
    void recall(void);

public slots:
    void pressed(void);
    void unpressed(void);

private:
    state _state;
    int _floor;
};

#endif // __BUTTON_H__