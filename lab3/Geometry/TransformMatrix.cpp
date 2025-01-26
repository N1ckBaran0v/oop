#include <cmath>

#include "Dot.h"
#include "TransformMatrix.h"
#include "Vector.h"

TransformMatrix::TransformMatrix(const Vector &offset) {
    xx = yy = zz = 1;
    dx = offset.x;
    dy = offset.y;
    dz = offset.z;
}

TransformMatrix::TransformMatrix(double angle, axis curr) {
    xx = yy = zz = 1;
    auto radians = (angle / 180) * M_PI;
    switch (curr) {
    case OX:
        yy = zz = cos(radians);
        zy = sin(radians);
        yz = -zy;
        break;
    case OY:
        zz = xx = cos(radians);
        xz = sin(radians);
        zx = -xz;
        break;
    case OZ:
        xx = yy = cos(radians);
        yx = sin(radians);
        xy = -yx;
        break;
    }
}

TransformMatrix::TransformMatrix(double cx, double cy, double cz)
    : xx(cx), yy(cy), zz(cz) {}

TransformMatrix::TransformMatrix(const Vector &vx, const Vector &vy,
                                 const Vector &vz) {
    xx = vx.x;
    xy = vx.y;
    xz = vx.z;
    yx = vy.x;
    yy = vy.y;
    yz = vy.z;
    zx = vz.x;
    zy = vz.y;
    zz = vz.z;
}

TransformMatrix TransformMatrix::operator*(const TransformMatrix &tm) {
    TransformMatrix result;

    result.xx = xx * tm.xx + xy * tm.yx + xz * tm.zx;
    result.xy = xx * tm.xy + xy * tm.yy + xz * tm.zy;
    result.xz = xx * tm.xz + xy * tm.yz + xz * tm.zz;

    result.yx = yx * tm.xx + yy * tm.yx + yz * tm.zx;
    result.yy = yx * tm.xy + yy * tm.yy + yz * tm.zy;
    result.yz = yx * tm.xz + yy * tm.yz + yz * tm.zz;

    result.zx = zx * tm.xx + zy * tm.yx + zz * tm.zx;
    result.zy = zx * tm.xy + zy * tm.yy + zz * tm.zy;
    result.zz = zx * tm.xz + zy * tm.yz + zz * tm.zz;

    result.dx = dx * tm.dx;
    result.dy = dy * tm.dy;
    result.dz = dz * tm.dz;

    return result;
}
