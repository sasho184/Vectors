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

    virtual bool operator==(const Element&) const;
    virtual std::ostream& ins(std::ostream&) const;

    virtual double length() const;
    virtual Element* direction() const;
    virtual Element* normal() const;
    double angle(Element*) const;
    virtual bool isZero() const;
    virtual bool isParallel(const Element&) const;
    virtual bool isPerpendicular(const Element&) const;

    virtual Element* operator+(const Element&) const { return 0; };
    virtual Element* operator-(const Element&) const { return 0; };
    virtual Element* operator^(const Element&) const { return 0; };
    virtual double operator()(const Element&, const Element&) const { return 0; };

    virtual bool operator||(const Element&) const { return 0; };
    Element* getPt() const { return 0; };

    virtual int type() { return 0; };
    virtual double S() { return 0; };
    virtual double P() { return 0; };
    virtual Element* centroid() { return 0; };
    virtual bool isInside(const Element&) const { return 0; };
    virtual bool liesOnPlane(const Element&) const { return 0; };
    virtual bool operator<(const Element&) const { return 0; };
    virtual bool operator>(const Element&) const { return 0; };

private:

};

