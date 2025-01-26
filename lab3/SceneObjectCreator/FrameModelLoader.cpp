#include "FrameModelLoader.h"

FrameModelLoader::FrameModelLoader(std::ifstream &input) : input(input) {}

Dot FrameModelLoader::createCenter() {
    auto x = 0.0, y = 0.0, z = 0.0;
    input >> x >> y >> z;
    return Dot(x, y, z);
}

std::vector<Dot> FrameModelLoader::createDots() {
    auto count = 0;
    input >> count;
    auto x = 0.0, y = 0.0, z = 0.0;
    std::vector<Dot> dots;
    for (auto i = 0; i < count; ++i) {
        input >> x >> y >> z;
        dots.emplace_back(x, y, z);
    }
    return dots;
}

std::vector<Segment> FrameModelLoader::createSegments() {
    auto count = 0;
    input >> count;
    auto first = 0, second = 0;
    std::vector<Segment> segments;
    for (auto i = 0; i < count; ++i) {
        input >> first >> second;
        segments.emplace_back(first, second);
    }
    return segments;
}
