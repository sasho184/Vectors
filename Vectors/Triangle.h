#pragma once
#include <iostream>
#include "Point.h"
#include "Vector.h"

using namespace std;

class Triangle: 
	public Point
{
public:
	Triangle();
	Triangle(Point, Point, Point);
	~Triangle();

	double getSideA();
	double getSideB();
	double getSideC();

	int type();
	double S();
	double P();
	Element* centroid();
	bool isInside(const Element&) const;
	bool liesOnPlane(const Element&) const;

	bool operator<(const Element&) const;
	bool operator>(const Element&) const;

private:
	Point B;
	Point C;

	double sideA;
	double sideB;
	double sideC;
};

double distance(Point, Point);