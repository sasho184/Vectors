#include "Triangle.h"

Triangle::Triangle()
{
	this->setX(0);
	this->setY(0);
	this->setZ(0);

	Point B(0, 0, 0);
	Point C(0, 0, 0);

	this->sideA = 0;
	this->sideB = 0;
	this->sideC = 0;

}

Triangle::Triangle(Point A , Point B, Point C)
{
	this->setX(A.getX());
	this->setY(A.getY());
	this->setZ(A.getZ());

	this->B = B;
	this->C = C;

	this->sideA = this->getSideA();
	this->sideB = this->getSideB();
	this->sideC = this->getSideC();
}

Triangle::~Triangle() {

}

double Triangle::getSideA() {
	return distance(B, C);
}

double Triangle::getSideB() {
	return distance(Point(this->getX(), this->getY(), this->getZ()), C);
}

double Triangle::getSideC() {
	return distance(Point(this->getX(), this->getY(), this->getZ()), B);
}

int Triangle::type() {

}

double distance(Point A, Point B) {
	return sqrt(pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2) + pow(A.getY() - B.getY(), 2));
}
