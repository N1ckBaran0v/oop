#ifndef __DOT_H__
#define __DOT_H__

class Vector;

class TransformMatrix;

class Dot {
public:
    Dot() = default;
    explicit Dot(double x, double y = 0, double z = 0);
    Dot(const Dot &, const Vector &);

    void transform(const Dot &, const TransformMatrix &);
    void move(const TransformMatrix &);
    Dot &operator +=(const Dot &);

    double x = 0;
    double y = 0;
    double z = 0;
};

static Dot CENTER = Dot();

#endif // __DOT_H__
