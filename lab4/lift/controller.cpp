#include "controller.h"

Controller::Controller(size_t floorsCnt) : QWidget(), _state(FREE) {
    _createLayouts();
    setLayout(_layoutDivider.get());

    _needVisit.resize(floorsCnt);
    _buttonsFloors.resize(floorsCnt);
    _buttonsLift.resize(floorsCnt);
    _indicatorsLift.resize(floorsCnt);

    for (size_t i = floorsCnt; i > 0; i--) {
        _createButtons(i - 1);
    }

    _indicatorsLift[_curFloor]->setStyleSheet(ACTIVE_STYLE);
    _indicatorsLift[_curFloor]->update();

    QObject::connect(this, SIGNAL(arrived()), this, SLOT(deactivate()));
    QObject::connect(this, SIGNAL(move(bool)), this, SLOT(activate(bool)));
}

void Controller::activate(bool isMoving) {
    if (_state == BUSY || _state == WAITING) {
        return;
    }
    
    _state = BUSY;
    if (!isMoving) {
        emit startMoving();
    }
}

void Controller::processCall(int floor) {
    _needVisit[floor] = true;
    if (_state != BUSY && _curFloor == floor) {
        _state = PROCESSING;
        emit arrived();
    }
    else if (_state == FREE || _state == BUSY) {
        bool flag = _state == BUSY;
        _selectTarget();
        _state = PROCESSING;
        emit move(flag);
    }
}

void Controller::needTarget(void) {
    if (_state != WAITING) {
        return;
    }

    _state = FREE;
    if (!(_selectTarget())) {
        qDebug() << "Waiting for signals...";
        return;
    }
    if (_curFloor == _targetFloor) {
        emit arrived();
        return;
    }
    emit move(false);
}

void Controller::floorChanged(void) {
    if (_state != BUSY) {
        return;
    }
    _state = SOLVING;
    _indicatorsLift[_curFloor]->setStyleSheet(INACTIVE_STYLE);
    _indicatorsLift[_curFloor]->update();
    _curFloor += _currDirect;
    _indicatorsLift[_curFloor]->setStyleSheet(ACTIVE_STYLE);
    _indicatorsLift[_curFloor]->update();
    if (_curFloor == _targetFloor) {
        emit arrived();
    }
    else {
        emit move(true);
    }
}

void Controller::deactivate(void) {
    emit _buttonsLift[_targetFloor]->recall();
    emit _buttonsFloors[_targetFloor]->recall();
    _needVisit[_targetFloor] = false;
    if (_state == SOLVING) {
        qDebug() << "The lift has arrived on the floor" << _targetFloor;
        _prevDirect = _currDirect;
        _currDirect = STAY;
    }
    _state = WAITING;
}

void Controller::_createLayouts(void) {
    _layoutDivider = std::make_unique<QHBoxLayout>();

    _layoutLift = std::make_unique<QVBoxLayout>();
    _labelLift = std::make_unique<QLabel>();
    _labelLift->setText(QString::fromUtf8("Lift"));
    _layoutLift->addWidget(_labelLift.get());

    _layoutFloors = std::make_unique<QVBoxLayout>();
    _labelFloors = std::make_unique<QLabel>();
    _labelFloors->setText(QString::fromUtf8("Floors"));
    _layoutFloors->addWidget(_labelFloors.get());

    _layoutIndicators = std::make_unique<QVBoxLayout>();
    _labelPos = std::make_unique<QLabel>();
    _labelPos->setText(QString::fromUtf8("Position"));
    _layoutIndicators->addWidget(_labelPos.get());

    _layoutDivider->addLayout(_layoutLift.get());
    _layoutDivider->addLayout(_layoutFloors.get());
    _layoutDivider->addLayout(_layoutIndicators.get());
}

void Controller::_createButtons(int floor) {
    _buttonsLift[floor] = _createButton(floor);
    _layoutLift->addWidget(dynamic_cast<QPushButton*>(_buttonsLift[floor].get()));
    _buttonsFloors[floor] = _createButton(floor);
    _layoutFloors->addWidget(dynamic_cast<QPushButton*>(_buttonsFloors[floor].get()));
    _indicatorsLift[floor] = std::make_unique<QPushButton>();
    _indicatorsLift[floor]->setStyleSheet(INACTIVE_STYLE);
    _indicatorsLift[floor]->update();
    _layoutIndicators->addWidget(_indicatorsLift[floor].get());
}

std::shared_ptr<Button> Controller::_createButton(int floor) {
    auto button = std::make_shared<Button>(floor);
    button->setText(QString::number(floor));
    QObject::connect(button.get(), SIGNAL(call(int)), this, SLOT(processCall(int)));
    return button;
}

bool Controller::_selectTarget(void) {
    bool flag = true;
    if (_needVisit[_curFloor] && _state != BUSY) {
        _targetFloor = _curFloor;
        flag = false;
    }
    else if (_currDirect != STAY) {
        for (int i = _curFloor + _currDirect; flag && i != _targetFloor; i += _currDirect) {
            if (_needVisit[i]) {
                _targetFloor = i;
                flag = false;
            }
        }
    }
    else if (_prevDirect != STAY){
        for (int i = _curFloor + _prevDirect; flag && i >= 0 && i < _needVisit.size(); i += _prevDirect) {
            if (_needVisit[i]) {
                _targetFloor = i;
                _currDirect = _prevDirect;
                flag = false;
            }
        }
        for (int i = _curFloor - _prevDirect; flag && i >= 0 && i < _needVisit.size(); i -= _prevDirect) {
            if (_needVisit[i]) {
                _targetFloor = i;
                _currDirect = Direction(-1 * _prevDirect);
                flag = false;
            }
        }
        _prevDirect = STAY;
    }
    else {
        for (int i = 1; flag && i >= 0 && i < _needVisit.size(); ++i) {
            if (_curFloor + i < _needVisit.size() && _needVisit[_curFloor + i]) {
                _targetFloor = _curFloor + i;
                _currDirect = UP;
                flag = false;
            }
            else if (_curFloor >= i && _needVisit[_curFloor - i]) {
                _targetFloor = _curFloor - i;
                _currDirect = DOWN;
                flag = false;
            }
            else if (_curFloor + i >= _needVisit.size() && _curFloor < i) {
                flag = false;
            }
        }
    }
    return !(flag);
}
