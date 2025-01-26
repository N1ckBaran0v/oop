#ifndef __MANAGER_VISITOR_H__
#define __MANAGER_VISITOR_H__

class SceneManager;

class LoadManager;

class TransformManager;

class DrawManager;

class ManagerVisitor {
public:
    virtual ~ManagerVisitor() = default;

    virtual void visit(SceneManager &) = 0;
    virtual void visit(LoadManager &) = 0;
    virtual void visit(TransformManager &) = 0;
    virtual void visit(DrawManager &) = 0;
};

#endif // __MANAGER_VISITOR_H__
