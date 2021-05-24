#include "Line.h"

Line::Line():Vector() {
	this->pt = Point();
}

Line::Line(Point pt, Vector v):Vector(v.getX(), v.getY(), v.getZ()) {
	this->pt = pt;
}

Line::Line(Point pt1, Point pt2):Vector(pt1, pt2) {
	this->pt = pt1;
}

Vector* Line::direction() const {
	return Vector::direction();
}

Vector Line::normal() const { // https://sciencing.com/plane-3-points-8123924.html
	double x, y, z;

	//x*v1 + y*v2 + z*v3 = 0 - dot product
	//x=1, y=1

	x = 1;
	y = 1;

	z = -(getX()+getY()) / getZ();

	return Vector(x, y, z);
}

double Line::angle(Vector v) const {
	//first find if the two lines intersect
	if (isParallel(v)) {

		//TODO Vector is parallel exception
		return 0;
	}
	
	return 0;
}

std::ostream& Line::ins(std::ostream& out) const {
	out << "Line vector x/y/z: " << getX() << "/" << getY() << "/" << getZ() << std::endl;
	out << "Line point x/y/z: " << pt.getX() << "/" << pt.getY() << "/" << pt.getZ() << std::endl;
	return out;
}