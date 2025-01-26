#ifndef __TRANSFORM_MANAGER_CREATOR_H__
#define __TRANSFORM_MANAGER_CREATOR_H__

#include <memory>

#include "../Manager/TransformManager.h"

class TransformManagerCreator {
public:
    TransformManagerCreator() = delete;

    static TransformManager &getManager();
};

#endif // __TRANSFORM_MANAGER_CREATOR_H__
