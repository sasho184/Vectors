#include <iostream>
#include <exception>
#include "Element.h"
#include "Point.h"
#include "Vector.h"

using namespace std;

int main() {

	Point A(1, 0, 1);
	Point B(2, 0, 2);

	Vector v1(A, B);
	Vector v2(2, 0, -2);

	cout << "v1 sides: " << endl;

	cout << v1.getX() << endl;
	cout << v1.getY() << endl;
	cout << v1.getZ() << endl;



	cout << "is Perpendicular " << v1.isPerpendicular(v2) << endl;

	return 0;
}