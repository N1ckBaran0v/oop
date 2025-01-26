#include "TransformManager.h"
#include "../ManagerVisitor/ManagerVisitor.h"
#include "../Geometry/Vector.h"

void TransformManager::accept(ManagerVisitor &visitor) {
    visitor.visit(*this);
}

TransformMatrix TransformManager::move(double dx, double dy, double dz) {
    return TransformMatrix(Vector(dx, dy, dz));
}

TransformMatrix TransformManager::rotate(double ox, double oy, double oz) {
    return (TransformMatrix(ox, OX) * TransformMatrix(oy, OY)) * TransformMatrix(oz, OZ);
}

TransformMatrix TransformManager::scale(double cx, double cy, double cz) {
    return TransformMatrix(cx, cy, cz);
}
