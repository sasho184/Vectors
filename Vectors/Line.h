#pragma once
#include "Vector.h"
class Line :
    public Vector
{
public:
    Line();
    Line(Point, Vector);
    Line(Point, Point);
    ~Line();

    Element* getPt() const;

    Element* direction() const;
    Element* normal() const;
    double angle(Element*) const;

    bool operator||(const Element&) const;

    bool operator==(const Element&) const;

private:
    Point pt;
};

double custPow(double, int);
bool operator+(const Point& lhs, const Line& rhs);