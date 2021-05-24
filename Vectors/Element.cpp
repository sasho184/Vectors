#include "Element.h"

Element::Element() {
	x = 0;
	y = 0;
	z = 0;
}

Element::Element(double x, double y, double z) :
	x(x), y(y), z(z) {

}

Element::Element(const Element& rhs) {
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

Element::~Element() {

}

Element& Element::operator=(const Element& rhs) {
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}
	return *this;
}

int Element::setX(double x) {
	this->x = x;
	return 0;
}

int Element::setY(double y) {
	this->y = y;
	return 0;
}

int Element::setZ(double z) {
	this->z = z;
	return 0;
}

bool Element::operator==(const Element& rhs) const {
	if (this == &rhs) {
		return true;
	}
	if (x == rhs.x && y == rhs.y && z == rhs.z) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& Element::ins(std::ostream& out) const {
	return out << "Element x/y/z: " << x << "/" << y << "/" << z;
}

std::ostream& operator<<(std::ostream& lhs, const Element& rhs) {
	return rhs.ins(lhs);
}