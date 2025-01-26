#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__

#include <memory>

#include "../Geometry/Dot.h"

class TransformMatrix;

class SceneVisitor;

class SceneObject {
public:
    virtual ~SceneObject() = default;

    virtual void transform(const TransformMatrix &) = 0;
    virtual bool isVisible() const = 0;
    virtual void accept(SceneVisitor &) = 0;
    virtual bool add(std::shared_ptr<SceneObject>);
    virtual bool remove(std::shared_ptr<SceneObject>);
    virtual bool isComposite() const;
    virtual std::shared_ptr<SceneObject> clone() const = 0;
    const Dot &getCenter() const;
    void setCenter(const Dot &);

protected:
    Dot center;
};

#endif // __SCENE_OBJECT_H__
