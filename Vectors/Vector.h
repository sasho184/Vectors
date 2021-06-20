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
    Element* direction() const;
    virtual Element* normal() const;
    bool isZero() const;
    bool isParallel(const Element&) const;
    bool isPerpendicular(const Element&) const;

    Element* operator+(const Element&) const; // subirane na dva vektora
    Element* operator-(const Element&) const; // izvajdane na dva vektora
    Element* operator^(const Element&) const; // vektorno proizvedenie na dva vektora
    double operator()(const Element&, const Element&) const; // smeseno proizvedenie na tri vektora

    virtual std::ostream& ins(std::ostream&) const;

private:

};

Vector operator*(double, const Element&); // umnojenie na vektor s realno chislo
double operator*(const Element&, const Element&); // skalarno proizvedenie na dva vektora