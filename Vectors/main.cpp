#include <iostream>
#include <exception>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "UserInterface.h"
#include "Triangle.h"

using namespace std;

int main() {
	bool exitProg = false;
	int entry = 0;
	int operation = 0;
	double x = 0, y = 0, z = 0;
	double x1, y1, z1;
	Element* object = nullptr;


	Point A(1,2,3);
	Point B(5,6,7);

	cout << distance(A, B);


	do {

		cout << "Select a geometric object: \n"
			<< "1 - Point\n"
			<< "2 - Vector\n"
			<< "3 - Line\n"
			<< "4 - Exit program\n";
		entry = inputDataInt(1, 4);

		switch (entry) {
		case 1:
			cout << endl << "Enter x,y and z for the point: ";
			cin >> x >> y >> z;
			object = new Point(x, y, z);

			pointOperation(object);
			break;
		case 2:
			cout << endl << "Enter x, y and z for the vector: ";
			cin >> x >> y >> z;
			object = new Vector(x, y, z);

			vectorOperation(object);
			break;
		case 3:
			cout << endl << "Enter x, y and z for the point: ";
			cin >> x >> y >> z;
			cout << endl << "Enter x, y and z for the vector: ";
			cin >> x1 >> y1 >> z1;
			object = new Line(Point(x, y, z), Vector(x1, y1, z1));

			lineOperation(object);
			break;
		case 4:
			exitProg = true;
			break;
		}

		if (object != nullptr) {
			delete object;
			object = nullptr;
		}
	} while (!exitProg);

	return 0;
}