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

double Vector::length() const {
	return sqrt(pow(this->getX(), 2) + pow(this->getY(), 2) + pow(this->getZ(), 2));
}

Vector* Vector::direction() const {
	if (this->isZero()) {
		throw VectorLengthException();
	}
	return new Vector((this->getX() / this->length()), (this->getY() / this->length()), (this->getZ() / this->length()));
}

bool Vector::isZero() const {
	if (this->getX() == 0 && this->getY() == 0 && this->getZ() == 0) {
		return true;
	}
	return false;
}

bool Vector::isParallel(const Vector& vector) const { // Checks if the three sides ratios are the same x.v1 + y.v2 + z.v3 = 0
	if (this->isZero()) {
		throw VectorLengthException();
	}
	if (((this->getX()/vector.getX()) == (this->getY()/vector.getY())) && ((this->getX() / vector.getX()) == (this->getZ() / vector.getZ()))) return true;
	return false;
}

bool Vector::isPerpendicular(const Vector& vector) const { // Checks if x.v1 + y.v2 + z.v3 = 0
	if (this->isZero()) {
		throw VectorLengthException();
	}
	if (((this->getX()*vector.getX()) + (this->getY()*vector.getY()) + (this->getZ()*vector.getZ())) == 0) return true;
	return false;
}

Vector* Vector::operator+(const Vector& rhs)  const{ // a + v = (x, y, z) + (v1, v2, v3) = (x + v1, y + v2, z + v3);
	return new Vector(getX() + rhs.getX(), getY() + rhs.getY(), getZ() + rhs.getZ());
}

Vector* Vector::operator-(const Vector& rhs) const { // a − v = (x, y, z) − (v1, v2, v3) = (x − v1, y − v2, z − v3)
	return new Vector(getX() - rhs.getX(), getY() - rhs.getY(), getZ() - rhs.getZ());
}

Vector* Vector::operator^(const Vector& rhs) const { // a ∧ v = (y.v3 − z.v2, −x.v3 + z.v1, x.v2 − y.v1).
	double x, y, z;

	x = getY() * rhs.getZ() - getZ() * rhs.getY();
	y = (-getX()) * rhs.getZ() + getZ() * rhs.getX();
	z = getX() * rhs.getY() - getY() * rhs.getX();

	return new Vector(x, y, z);
}

Vector operator*(int r, const Vector& rhs) { // r ∗ a = (rx, ry, rz);
	return Vector(r * rhs.getX(), r * rhs.getY(), r * rhs.getZ());
}

double operator*(const Vector& lhs, const Vector& rhs) { // a ∗ v = x.v1 + y.v2 + z.v3
	return lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY() + lhs.getZ() * rhs.getZ();
}

double Vector::operator()(const Vector& v, const Vector& w) const {	//Mixed product of three vectors - Sarus
	double a, b;

	a = (this->getX() * v.getY() * w.getZ() + this->getY() * v.getZ() * w.getX() + this->getZ() * v.getX() * w.getY());
	b = (this->getZ() * v.getY() * w.getX() + this->getX() * v.getZ() * w.getY() + this->getY() * v.getX() * w.getZ());

	return a - b;
}

std::ostream& Vector::ins(std::ostream& out) const {
	return out << "Vector x/y/z: " << getX() << "/" << getY() << "/" << getZ();
}

/*
std::ostream& operator<<(std::ostream&, const Element&) {

}
*/