#include "Line.h"

Line::Line() :Vector() {
	this->pt = Point();
}

Line::Line(Point pt, Vector v):Vector(v.getX(), v.getY(), v.getZ()) {
	this->pt = pt;
}

Line::Line(Point pt1, Point pt2):Vector(pt1, pt2) {
	this->pt = pt1;
}

Line::~Line() {

}

Element* Line::getPt() const{
	return new Point(pt.getX(), pt.getY(), pt.getZ());
}

Element* Line::direction() const {

	return Vector::direction();
}

Element* Line::normal() const { // https://sciencing.com/plane-3-points-8123924.html
	//https://math.stackexchange.com/questions/3451205/find-normal-vector-of-a-3d-vector
	//https://math.stackexchange.com/questions/137362/how-to-find-perpendicular-vector-to-another-vector
	double x, y, z;

	x = -((getY()+pt.getY()) - pt.getY());
	y = ((getX()+pt.getX()) - pt.getX());
	z = 0;

	return new Vector(x, y, z);
}

double Line::angle(Element* v) const {//https://www.youtube.com/watch?v=QWIZXRjMspI //TODO this works sometimes
	if (isParallel(*v)) {
		//TODO Vector is parallel exception
		std::cout << std::endl << "The two lines are Parallel" << std::endl;
		//return 0;
	}

	double angle = 0;

	double dot = ((Vector)*this) * (*v);

	double v1Len = this->length();
	double v2Len = v->length();

	angle = acos(dot / (v1Len * v2Len));
	
	return angle;
}

double custPow(double base, int exp) {
	double val = 0;
	if (base < 0) {
		val = -(pow(base, exp));
	}
	else {
		val = pow(base, exp);
	}
	return val;
}

bool Line::operator||(const Element& rhs) const {
	if (isParallel(rhs)) {
		return true;
	}
	return false;
}

bool Line::operator==(const Element& rhs) const {
	Element* pt1 = this->getPt();
	Element* pt2 = rhs.getPt();

	std::cout << "teardasfas";
	if (getX() == rhs.getX() && getY() == rhs.getY() && getZ() == rhs.getZ() && *pt1 == *pt2) {
		delete pt1;
		delete pt2;
		return true;
	}
	delete pt1;
	delete pt2;
	return false;
}

bool operator+(const Point& lhs, const Line& rhs) {

	return 0;
}
