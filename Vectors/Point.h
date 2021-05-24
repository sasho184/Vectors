#pragma once
#include "Element.h"
class Point :
    public Element
{
public:
    Point();
    Point(double, double, double);
    ~Point();
    Point(const Point&);
    Point& operator=(const Point&);


    bool operator==(const Point&) const;

    virtual double length() const;
    virtual Point* direction() const;
    virtual bool isZero() const;
    virtual bool isParallel(const Element&) const;
    virtual bool isPerpendicular(const Element&) const;

    //virtual std::ostream& ins(std::ostream&) const;

private:

};

