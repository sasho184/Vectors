#include <iostream>
#include <exception>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "UserInterface.h"

using namespace std;

int main() {
	bool exitProg = false;
	int entry = 0;
	int operation = 0;
	double x = 0, y = 0, z = 0;
	Element* object = nullptr;

	Vector v1(1, 2, 3);
	Vector v2(4, 5, 6);

	//cout << v1 + v2;


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

			if (object != nullptr) {
				delete object;
				object = nullptr;
			}
			
			break;
		case 3:
			break;
		case 4:
			exitProg = true;
			break;
		}
	} while (!exitProg);

	return 0;
}