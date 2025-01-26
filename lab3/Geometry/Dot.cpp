#include "Dot.h"
#include "Vector.h"
#include "TransformMatrix.h"

Dot::Dot(double x, double y, double z) : x(x), y(y), z(z) {}

Dot::Dot(const Dot &start, const Vector &offset) {
    x = start.x + offset.x;
    y = start.y + offset.y;
    z = start.z + offset.z;
}

void Dot::transform(const Dot &center, const TransformMatrix &tm) {
    Vector offset(center, *this);
    offset.transform(tm);
    *this = Dot(center, offset);
}

void Dot::move(const TransformMatrix &tm) {
    x += tm.dx;
    y += tm.dy;
    z += tm.dz;
}

Dot &Dot::operator +=(const Dot &another) {
    x += another.x;
    y += another.y;
    z += another.z;
    return *this;
}
