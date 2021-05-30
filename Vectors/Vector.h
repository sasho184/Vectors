#pragma once
#include "Point.h"
#include "Exceptions.h"
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

    double length() const;
    Vector direction() const;
    bool isZero() const;
    bool isParallel(const Vector&) const;
    bool isPerpendicular(const Vector&) const;

    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Vector operator^(const Vector&) const;
    double operator()(const Vector&, const Vector&) const;


private:

};

Vector operator*(int, const Vector&);
double operator*(const Vector&, const Vector&);