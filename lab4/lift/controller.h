#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <memory>
#include <vector>
#include <cstddef>
#include <QDebug>

#include "settings.h"
#include "button.h"

class Controller : public QWidget {
    Q_OBJECT
    enum state {FREE, PROCESSING, BUSY, SOLVING, WAITING};
    enum Direction {DOWN = -1, STAY = 0, UP = 1};

public:
    Controller(size_t floorsCnt);
    ~Controller(void) = default;

signals:
    void startMoving(void);
    void move(bool);
    void arrived(void);

public slots:
    void activate(bool);
    void processCall(int);
    void needTarget(void);
    void floorChanged(void);
    void deactivate(void);

private:
    void _createLayouts(void);
    void _createButtons(int floor);
    std::shared_ptr<Button> _createButton(int floor);
    bool _selectTarget(void);

private:
    state _state;

    int _curFloor = 0;
    int _targetFloor = 0;
    std::vector<bool> _needVisit;

    Direction _currDirect = STAY;
    Direction _prevDirect = STAY;

    std::vector<std::shared_ptr<Button>> _buttonsLift;
    std::vector<std::shared_ptr<Button>> _buttonsFloors;
    std::vector<std::shared_ptr<QPushButton>> _indicatorsLift;

    std::unique_ptr<QHBoxLayout> _layoutDivider;
    std::unique_ptr<QVBoxLayout> _layoutLift;
    std::unique_ptr<QVBoxLayout> _layoutFloors;
    std::unique_ptr<QVBoxLayout> _layoutIndicators;
    std::unique_ptr<QLabel> _labelLift;
    std::unique_ptr<QLabel> _labelFloors;
    std::unique_ptr<QLabel> _labelPos;
};

#endif // __CONTROLLER_H__