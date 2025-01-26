#ifndef __SCENEVISITOR_H__
#define __SCENEVISITOR_H__

class Camera;

class FrameModel;

class Composite;

class SceneVisitor {
public:
    virtual ~SceneVisitor() = default;

    virtual void visit(Camera &) = 0;
    virtual void visit(FrameModel &) = 0;
    virtual void visit(Composite &) = 0;
};

#endif // __SCENEVISITOR_H__
