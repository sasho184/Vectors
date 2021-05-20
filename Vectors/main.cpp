#include <iostream>
#include <exception>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Line.h"

using namespace std;

int main() {

	Point A(0, 0, 0);
	Point B(5, 22, 6);

	Line l1(A, B);
	
	cout << l1.normal().getX() << endl << l1.normal().getY() << endl << l1.normal().getZ() << endl;

	return 0;
}