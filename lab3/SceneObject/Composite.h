#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

#include <vector>

#include "Visible.h"

class Composite : public Visible {
public:
    Composite() = default;
    void transform(const TransformMatrix &) override;
    void accept(SceneVisitor &) override;
    bool add(std::shared_ptr<SceneObject>) override;
    bool remove(std::shared_ptr<SceneObject>) override;
    bool isComposite() const override;
    std::shared_ptr<SceneObject> clone() const override;

private:
    std::vector<std::weak_ptr<SceneObject>> objects;

    void calculateCenter();
    void deleteExpired();
};

#endif // __COMPOSITE_H__
