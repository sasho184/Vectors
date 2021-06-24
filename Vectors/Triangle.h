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
	Point centroid();
	bool isInside(Point);

private:
	Point B;
	Point C;

	double sideA;
	double sideB;
	double sideC;
};

double distance(Point, Point);