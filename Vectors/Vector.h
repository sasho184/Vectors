#pragma once
#include "Point.h"
#include <cmath>

class Vector :
    public Point
{
public:
    Vector();
    Vector(double, double, double);
    Vector(Point, Point);
    ~Vector();
    Vector(const Vector&);
    Vector& operator=(const Vector&);

    double Length() const;
    Vector Direction() const;
    bool isZero() const;
    bool isParallel(const Vector&) const;
    bool isPerpendicular(const Vector&) const;

private:

};

