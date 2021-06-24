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


bool Point::operator==(const Element& rhs) const {
	if (this == &rhs) {
		return true;
	}
	if (this->getX() == rhs.getX() && this->getX() == rhs.getY() && this->getZ() == rhs.getZ()) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& Point::ins(std::ostream& out) const {
	return out << "Point x/y/z: " << getX() << "/" << getY() << "/" << getZ();
}

double Point::length() const {
	return 0;
}

Element* Point::direction() const {
	return 0;
}

Element* Point::normal() const {
	return 0;
}

double Point::angle(Element*) const {
	return 0;
}

bool Point::isZero() const {
	return 0;
}

bool Point::isParallel(const Element&) const {
	return 0;
}

bool Point::isPerpendicular(const Element&) const {
	return 0;
}
