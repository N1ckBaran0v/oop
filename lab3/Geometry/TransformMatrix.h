#ifndef __TRANSFORM_MATRIX_H__
#define __TRANSFORM_MATRIX_H__

class Vector;

enum axis { OX, OY, OZ };

class TransformMatrix {
public:
    TransformMatrix() = default;
    TransformMatrix(const Vector &);
    TransformMatrix(double, double, double);
    TransformMatrix(double, axis);
    TransformMatrix(const Vector &, const Vector &, const Vector &);

    TransformMatrix operator*(const TransformMatrix &);

    double xx = 1, yx = 0, zx = 0, dx = 0;
    double xy = 0, yy = 1, zy = 0, dy = 0;
    double xz = 0, yz = 0, zz = 1, dz = 0;
};

#endif // __TRANSFORM_MATRIX_H__
