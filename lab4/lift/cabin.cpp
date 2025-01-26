#include "cabin.h"

Cabin::Cabin(void) : QObject(), _state(WAITING), _doors(std::make_unique<Doors>()) {
    QObject::connect(this, SIGNAL(arrived()), _doors.get(), SLOT(opening()));
    QObject::connect(_doors.get(), SIGNAL(closed()), this, SLOT(wait()));
    QObject::connect(&_movingTimer, SIGNAL(timeout()), this, SLOT(move()));
}

void Cabin::wait(void) {
    if (_state != STAYING) {
        return;
    }

    _state = WAITING;
    emit needTarget();
}

void Cabin::move(void) {
    if (_state == STAYING) {
        return;
    }

    if (_state == MOVING) {
        emit floorChanged();
    }
    else {
        _state = MOVING;
        qDebug() << "The lift started moving";
        _movingTimer.start(MOVING_TIME);
    }
}

void Cabin::stop(void) {
    _movingTimer.stop();
    if (_state == MOVING) {
        qDebug() << "The lift stopped";
    }
        
    this->_state = STAYING;
    emit arrived();
}
