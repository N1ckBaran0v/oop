#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "../Geometry/Vector.h"
#include "Invisible.h"

class Camera : public Invisible {
public:
    friend class DrawVisitor;

    Camera();

    void transform(const TransformMatrix &) override;
    void accept(SceneVisitor &) override;
    std::shared_ptr<SceneObject> clone() const override;

private:
    Vector vx, vy, vz;
};

#endif // __CAMERA_H__
