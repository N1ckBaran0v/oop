#include "FrameModel.h"
#include "../SceneVisitor/SceneVisitor.h"

FrameModel::FrameModel(const Dot &center, const std::vector<Dot> &dots,
                       const std::vector<Segment> &segments)
    : dots(dots), segments(segments) {
    this->center = center;
}

void FrameModel::transform(const TransformMatrix &tm) {
    for (auto& dot : dots) {
        dot.transform(center, tm);
    }
    center.move(tm);
}

void FrameModel::accept(SceneVisitor &visitor) {
    visitor.visit(*this);
}

std::shared_ptr<SceneObject> FrameModel::clone() const {
    return std::make_shared<FrameModel>(center, dots, segments);
}
