#include "Triangle.h"
#include <cmath>

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
	return distance(C, B);
}

double Triangle::getSideB() {
	return distance(Point(this->getX(), this->getY(), this->getZ()), C);
}

double Triangle::getSideC() {
	return distance(Point(this->getX(), this->getY(), this->getZ()), B);
}

int Triangle::type() {
	
	cout << "The triangle is ";

	if (sideA == sideB && sideA == sideC && sideB == sideC) {
		cout << "equilateral.";
	}
	else if (sideA == sideB || sideA == sideC || sideB == sideC) {
		cout << "isosceles.";
	}
	else if ( sideA*sideA == (sideB * sideB + sideC * sideC) || sideB * sideB == (sideC * sideC + sideA * sideA) || sideC * sideC == (sideA * sideA + sideB * sideB)) {
		cout << "right angled.";
	}

	return 0;
}

double Triangle::S() {
	double p = (sideA + sideB + sideC)/2;

	std::cout << sideA << " " << sideB << " " << sideC << std::endl;

	std::cout << p << std::endl;

	return sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));
}

double Triangle::P() {
	return sideA + sideB + sideC;
}

Point Triangle::centroid() {
	double x, y, z;

	x = (getX() + B.getX() + C.getX()) / 3;
	y = (getY() + B.getY() + C.getY()) / 3;
	z = (getZ() + B.getZ() + C.getZ()) / 3;
	
	return Point(x, y, z);
}

bool Triangle::isInside(Point pt) { // https://stackoverflow.com/questions/37545304/determine-if-point-is-inside-triangle-in-3d

	Vector vectC(Point(this->getX(), this->getY(), this->getZ()), B);
	Vector vectA(B, C);
	Vector vectB(C, Point(this->getX(), this->getY(), this->getZ()));

	Vector vectAP(Point(this->getX(), this->getY(), this->getZ()), pt);
	Vector vectBP(B, pt);
	Vector vectCP(C, pt);

	double dotAPC;
	double dotBPA;
	double dotCPB;

	dotAPC = vectAP * vectC;
	dotBPA = vectBP * vectA;
	dotCPB = vectCP * vectB;

	cout << dotAPC << " " << dotBPA << " " << dotCPB << " ";

	if(dotAPC > 0 && dotBPA > 0 && dotCPB > 0){
		return true;
	}

	return false;
}

double distance(Point A, Point B) {
	return sqrt(pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2) + pow(A.getZ() - B.getZ(), 2));
}
