#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include <cstddef>

class Segment {
public:
    Segment() = default;
    Segment(size_t, size_t);

    size_t first = 0;
    size_t second = 0;
};

#endif // __SEGMENT_H__
