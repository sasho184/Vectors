#include <iostream>
#include "Element.h"
#include "Point.h"
#include "Vector.h"

using namespace std;

int main() {

	Point A(25.3, -2, -87);
	Point B(36, -22.2, -3.56);

	Vector v1(A, B);
	Vector v2(0, 0, 0);

	Vector v1Len(v1.Direction());


	cout << v1Len.getX() << endl;
	cout << v1Len.getY() << endl;
	cout << v1Len.getZ() << endl;

	cout << "v1Len length " << v1Len.Length() << endl;


	cout << "is zero " << v2.isZero() << endl;

	return 0;
}