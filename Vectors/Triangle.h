#pragma once
#include <iostream>
#include "Point.h"

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

private:
	Point B;
	Point C;

	double sideA;
	double sideB;
	double sideC;
};

double distance(Point, Point);