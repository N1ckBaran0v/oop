#include "lift.h"

Lift::Lift(size_t floors) : QObject() {
    _controller = std::make_shared<Controller>(floors);
    _cabin = std::make_shared<Cabin>();
    QObject::connect(_cabin.get(), SIGNAL(needTarget()), _controller.get(), SLOT(needTarget()));
    QObject::connect(_cabin.get(), SIGNAL(floorChanged()), _controller.get(), SLOT(floorChanged()));
    QObject::connect(_controller.get(), SIGNAL(startMoving()), _cabin.get(), SLOT(move()));
    QObject::connect(_controller.get(), SIGNAL(arrived()), _cabin.get(), SLOT(stop()));
}

std::shared_ptr<Controller> Lift::getController(void) {
    return _controller;
}
