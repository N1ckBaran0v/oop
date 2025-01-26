#ifndef __VECTOR_H__
#define __VECTOR_H__

class Dot;

class TransformMatrix;

class Vector {
public:
    Vector() = default;
    explicit Vector(double x, double y = 0, double z = 0);
    Vector(const Dot &, const Dot &);

    void transform(const TransformMatrix &);
    void normalize();

    double x = 0;
    double y = 0;
    double z = 0;
};

#endif // __VECTOR_H__
