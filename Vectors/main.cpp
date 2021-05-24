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

	Vector v1(1, 2, 3);

	Vector v2(4, 5, 6);

	Vector v3(7, 8, 9);
	
	cout << v1(v2, v3);

	return 0;
}