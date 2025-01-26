#ifndef __FRAME_MODEL_LOADER_H__
#define __FRAME_MODEL_LOADER_H__

#include <fstream>

#include "FrameModelBuilder.h"

class FrameModelLoader : public FrameModelBuilder {
public:
    FrameModelLoader() = delete;
    FrameModelLoader(std::ifstream &);

    Dot createCenter() override;
    std::vector<Dot> createDots() override;
    std::vector<Segment> createSegments() override;

private:
    std::ifstream &input;
};

#endif // __FRAME_MODEL_LOADER_H__
