#include "DrawVisitor.h"
#include "../Geometry/Dot.h"
#include "../Geometry/Segment.h"
#include "../Geometry/TransformMatrix.h"
#include "../Geometry/Vector.h"
#include "../SceneObject/Camera.h"
#include "../SceneObject/FrameModel.h"

#include <iostream>

DrawVisitor::DrawVisitor(const Camera &camera,
                         std::shared_ptr<WindowAdapter> adapter)
    : camera(camera), adapter(adapter) {}

void DrawVisitor::visit(Camera &camera) {}

void DrawVisitor::visit(FrameModel &model) {
    TransformMatrix tm(camera.vx, camera.vy, camera.vz);
    std::vector<Dot> transformed;
    for (const auto &dot : model.dots) {
        Vector tmp(camera.center, dot);
        tmp.transform(tm);
        transformed.emplace_back(CENTER, tmp);
    }
    for (const auto &segment : model.segments) {
        adapter->drawLine(
            transformed[segment.first].x, transformed[segment.first].y,
            transformed[segment.second].x, transformed[segment.second].y);
    }
}

void DrawVisitor::visit(Composite &composite) {}
