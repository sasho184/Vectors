#include "Point.h"

Point::Point() :Element() {

}

Point::Point(double x, double y, double z) : Element(x, y, z) {

}

Point::~Point() {

}

Point::Point(const Point& rhs) :Element(rhs) {

}

Point& Point::operator=(const Point& rhs) {
	if (this != &rhs) {
		Element::operator=(rhs);
	}
	return *this;
}


bool Point::operator==(const Point& rhs) const {
	return Element::operator==(rhs);
}