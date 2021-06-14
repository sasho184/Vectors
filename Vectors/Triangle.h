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

	


private:
	Point A;
	Point B;
	Point C;
};