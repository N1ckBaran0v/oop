#ifndef __TRANSFORM_MANAGER_H__
#define __TRANSFORM_MANAGER_H__

#include "../Geometry/TransformMatrix.h"
#include "BaseManager.h"

class TransformManager : public BaseManager {
public:
    void accept(ManagerVisitor &) override;
    TransformMatrix move(double dx, double dy, double dz);
    TransformMatrix rotate(double ox, double oy, double oz);
    TransformMatrix scale(double cx, double cy, double cz);
};

#endif // __TRANSFORM_MANAGER_H__
