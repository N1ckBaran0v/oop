#include "button.h"

Button::Button(int floor) : QPushButton(), _floor(floor), _state(INACTIVE) {
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressed()));
    QObject::connect(this, SIGNAL(recall()), this, SLOT(unpressed()));

    setStyleSheet(INACTIVE_STYLE);
    update();
}

void Button::pressed(void) {
    if (_state != INACTIVE) {
        return;
    }

    _state = ACTIVE;
    setStyleSheet(ACTIVE_STYLE);
    update();
    setDisabled(true);
    qDebug() << "Call to the floor" << _floor;
    emit call(_floor);
}

void Button::unpressed(void) {
    if (_state != ACTIVE) {
        return;
    }

    _state = INACTIVE;
    setStyleSheet(INACTIVE_STYLE);
    update();
    setDisabled(false);
}
