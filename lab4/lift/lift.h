#ifndef __LIFT_H__
#define __LIFT_H__

#include <QObject>
#include <memory>

#include "cabin.h"
#include "controller.h"

class Lift : public QObject {
    Q_OBJECT

public:
    Lift(size_t floors);
    ~Lift(void) = default;
    std::shared_ptr<Controller> getController(void);

private:
    std::shared_ptr<Controller> _controller;
    std::shared_ptr<Cabin> _cabin;
};

#endif // __LIFT_H__