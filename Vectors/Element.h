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

private:
	double x;
	double y;
	double z;

};

