#ifndef __DRAW_MANAGER_H__
#define __DRAW_MANAGER_H__

#include <memory>
#include <string>

#include "../WindowAdapter/WindowAdapter.h"
#include "BaseManager.h"

class DrawManager : public BaseManager {
public:
    void accept(ManagerVisitor &) override;
    void draw(const std::string &, std::shared_ptr<WindowAdapter>);
};

#endif // __DRAW_MANAGER_H__
