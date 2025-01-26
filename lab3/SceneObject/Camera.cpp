#include "Camera.h"
#include "../SceneVisitor/SceneVisitor.h"
#include "../Geometry/TransformMatrix.h"

Camera::Camera() : vx(1, 0, 0), vy(0, 1, 0), vz(0, 0, 1) {}

void Camera::transform(const TransformMatrix &tm) {
    center.move(tm);
    auto ttm = tm;
    ttm.dx = ttm.dy = ttm.dz = 0;
    vx.transform(ttm);
    vy.transform(ttm);
    vz.transform(ttm);
    vx.normalize();
    vy.normalize();
    vz.normalize();
}

void Camera::accept(SceneVisitor &visitor) { visitor.visit(*this); }

std::shared_ptr<SceneObject> Camera::clone() const {
    std::shared_ptr<SceneObject> clone = std::make_shared<Camera>(*this);
    return clone;
}
