#ifndef __FRAME_MODEL_H__
#define __FRAME_MODEL_H__

#include <vector>

#include "../Geometry/Segment.h"
#include "Visible.h"

class FrameModel : public Visible {
public:
    friend class DrawVisitor;

    FrameModel() = delete;
    FrameModel(const Dot &, const std::vector<Dot> &,
               const std::vector<Segment> &);

    void transform(const TransformMatrix &) override;
    void accept(SceneVisitor &) override;
    std::shared_ptr<SceneObject> clone() const override;

private:
    std::vector<Dot> dots;
    std::vector<Segment> segments;
};

#endif // __FRAME_MODEL_H__
