#include "Vector.h"

Vector::Vector() :Point() {

}

Vector::Vector(double x, double y, double z) : Point(x, y, z) {

}

Vector::Vector(Point A, Point B) {
	this->setX(B.getX() - A.getX());
	this->setY(B.getY() - A.getY());
	this->setZ(B.getZ() - A.getZ());
}

Vector::~Vector() {

}

Vector::Vector(const Vector& rhs) :Point(rhs) {

}

Vector& Vector::operator=(const Vector& rhs) {
	if (this != &rhs) {
		Element::operator=(rhs);
	}
	return *this;
}

double Vector::Length() const {
	return sqrt(pow(this->getX(), 2) + pow(this->getY(), 2) + pow(this->getZ(), 2));
}

//TODO VectorLengthException
Vector Vector::Direction() const {
	return Vector((this->getX() / this->Length()), (this->getY() / this->Length()), (this->getZ() / this->Length()));
}

bool Vector::isZero() const {
	if (this->getX() == 0 && this->getY() == 0 && this->getZ() == 0) {
		return true;
	}
	return false;
}