#ifndef __LOAD_MANAGER_CREATOR_H__
#define __LOAD_MANAGER_CREATOR_H__

#include <memory>

#include "../Manager/LoadManager.h"

class LoadManagerCreator {
public:
    LoadManagerCreator() = delete;

    static LoadManager &getManager();

private:
    static std::unique_ptr<LoadManager> manager;
};

#endif // __LOAD_MANAGER_CREATOR_H__
