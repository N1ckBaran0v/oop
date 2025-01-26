#ifndef __DRAW_VISITOR_H__
#define __DRAW_VISITOR_H__

#include <memory>

#include "../WindowAdapter/WindowAdapter.h"
#include "SceneVisitor.h"

class DrawVisitor : public SceneVisitor {
public:
    DrawVisitor(const Camera &, std::shared_ptr<WindowAdapter>);

    void visit(Camera &) override;
    void visit(FrameModel &) override;
    void visit(Composite &) override;

private:
    const Camera &camera;
    std::shared_ptr<WindowAdapter> adapter;
};

#endif // __DRAW_VISITOR_H__
