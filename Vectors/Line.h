#pragma once
#include "Vector.h"
class Line :
    public Vector
{
public:
    Line();
    Line(Point, Vector);
    Line(Point, Point);

    Element* direction() const;
    Vector normal() const;
    double angle(Vector) const;

private:
    Point pt;
};

