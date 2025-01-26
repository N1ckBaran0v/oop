#include <cmath>

#include "Vector.h"
#include "Dot.h"
#include "TransformMatrix.h"

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

Vector::Vector(const Dot &first, const Dot &second) {
    x = second.x - first.x;
    y = second.y - first.y;
    z = second.z - first.z;
}

void Vector::transform(const TransformMatrix &tm) {
    auto tx = tm.xx * x + tm.xy * y + tm.xz * z + tm.dx;
    auto ty = tm.yx * x + tm.yy * y + tm.yz * z + tm.dy;
    auto tz = tm.zx * x + tm.zy * y + tm.zz * z + tm.dz;
    x = tx;
    y = ty;
    z = tz;
}

void Vector::normalize() {
    auto length = sqrt(x * x + y * y + z * z);
    x /= length;
    y /= length;
    z /= length;
}
