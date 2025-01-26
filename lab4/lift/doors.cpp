#include "doors.h"

Doors::Doors(void) : QObject(), _state(CLOSED) {
    QObject::connect(&_openingTimer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&_openedTimer, SIGNAL(timeout()), this, SLOT(closing()));
    QObject::connect(&_closingTimer, SIGNAL(timeout()), this, SLOT(close()));
}

void Doors::closing(void) {
    if (_state != OPENED) {
        return;
    }
    _openedTimer.stop();
    _state = CLOSING;
    qDebug() << "Start closing doors...";
    _closingTimer.start(CLOSING_TIME);
}

void Doors::opening(void) {
    if (_state == OPENING || _state == OPENED) {
        return;
    }
    
    if (_state == CLOSED) {
        _state = OPENING;
        qDebug() << "Start opening doors...";
        _openingTimer.start(OPENING_TIME);
    }
    else {
        _state = OPENING;
        auto remTime = _closingTimer.remainingTime();
        _closingTimer.stop();
        qDebug() << "Stop closing doors. Opening doors...";
        _openingTimer.start(OPENING_TIME - remTime);
    }
}

void Doors::close(void) {
    if (_state != CLOSING) {
        return;
    }
    _closingTimer.stop();
    _state = CLOSED;
    qDebug() << "The doors closed";
    emit closed();
}

void Doors::open(void) {
    if (_state != OPENING && _state != OPENED) {
        return;
    }
    _openingTimer.stop();
    
    if (_state == OPENING) {
        qDebug() << "The doors opened";
    }
    _state = OPENED;
    _openedTimer.start(OPENED_TIME);
}