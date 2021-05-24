#pragma once
#include <iostream>

class Element
{
public:
	Element();
	Element(double, double, double);
	Element(const Element&);
	~Element();
	Element& operator=(const Element&);

	int setX(double);
	int setY(double);
	int setZ(double);

	double getX() const { return x; };
	double getY() const { return y; };
	double getZ() const { return z; };

	virtual bool operator==(const Element&) const;

	virtual double length() const=0;
	virtual Element* direction() const=0;
	virtual bool isZero() const=0;
	virtual bool isParallel(const Element&) const=0;
	virtual bool isPerpendicular(const Element&) const=0;

	virtual std::ostream& ins(std::ostream&) const;

private:
	double x;
	double y;
	double z;

};

std::ostream& operator<<(std::ostream&, const Element&);