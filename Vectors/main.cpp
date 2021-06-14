#include <iostream>
#include <exception>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Line.h"


using namespace std;

int main() {

	Element e(0,0,0);

	Point A(0, 0, 0);
	Point B(5, 22, 6);
	Point C(3, 4, 0);

	Line l1(A, B);
	
	Vector v1(A, B);

	cout << v1;

	return 0;
}