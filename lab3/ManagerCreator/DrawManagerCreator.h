#ifndef __DRAW_MANAGER_CREATOR_H__
#define __DRAW_MANAGER_CREATOR_H__

#include <memory>

#include "../Manager/DrawManager.h"

class DrawManagerCreator {
public:
    DrawManagerCreator() = delete;

    static DrawManager &getManager();
};

#endif // __DRAW_MANAGER_CREATOR_H__
