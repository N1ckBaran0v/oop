#ifndef __FRAME_MODEL_BUILDER_H__
#define __FRAME_MODEL_BUILDER_H__

#include <vector>

#include "../Geometry/Dot.h"
#include "../Geometry/Segment.h"

class FrameModelBuilder
{
public:
    virtual ~FrameModelBuilder() = default;

    virtual Dot createCenter() = 0;
    virtual std::vector<Dot> createDots() = 0;
    virtual std::vector<Segment> createSegments() = 0;
};

#endif // __FRAME_MODEL_BUILDER_H__
