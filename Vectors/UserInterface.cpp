#include "UserInterface.h"

int inputDataInt(int x, int y) {
	//Gets input from user and checks if the data is valid
	int a;
	std::cin >> a;
	while (a < x || a > y) {
		std::cout << "Data is invalid. Please enter a number in range from " << x << " to " << y << std::endl;
		std::cin >> a;
		std::cout << std::endl;
	}
	return a;
}

char inputDataYN() {
	char input;
	std::cin >> input;
	while(input != 'y' && input != 'n'){
		std::cout << "Invalid Input. Enter y or n: ";
		std::cin >> input;
		std::cout << std::endl;
	}
	return input;
}

int inputSecVect(double& x, double& y, double& z) {
	std::cout << "Enter x, y and z for the vector: ";
	std::cin >> x >> y >> z;
	return 0;
}

int pointOperation(Element* pt1) {
	char cont = 'n';
	int operation;
	double x, y, z;
	bool result = false;
	Element* returnObject = nullptr;
	Element* pt2 = nullptr;

	do {
		std::cout << std::endl << "Select an operation from the menu: \n"
			<< "1  - Check if two points match\n";

		operation = inputDataInt(1, 11);
		cont = 'n';
		switch (operation) {
		case 1:
			std::cout << "Enter x, y and z for the point: ";
			std::cin >> x >> y >> z;
			pt2 = new Point(x, y, z);
			std::cout << std::endl << "The points" << ((*pt1 == *pt2) ? " " : " don't ") << "match.";
			break;
		}

		if (returnObject != nullptr) {
			delete returnObject;
			returnObject = nullptr;
		}

		std::cout << std::endl << "Do you want to select a new operation?(y/n) ";
		cont = inputDataYN();
	} while (cont == 'y');
	return 0;
}

int vectorOperation(Element* vect1) {
	char cont = 'n';
	int operation;
	double num;
	double x, y, z;
	bool result = false;
	Element* returnObject = nullptr;
	Element* vect2 = nullptr;
	Element* vect3 = nullptr;

	do {
		std::cout << std::endl << "Select an operation from the menu: \n"
			<< "1  - Calculate vector length\n"
			<< "2  - Calculate vector direction\n"
			<< "3  - Check for zero vector\n"
			<< "4  - Check if two vectors are parallel\n"
			<< "5  - Check if two vectors are perpendicular\n"
			<< "6  - Addition with another vector\n"
			<< "7  - Subtractction with another vector\n"
			<< "8  - Multiplication with a real number\n"
			<< "9  - Scalar product of two vectors\n"
			<< "10 - Vector product of two vectors\n"
			<< "11 - Mixed product of three vectors\n";

		operation = inputDataInt(1, 11);
		cont = 'n';
		switch (operation) {
		case 1:
			std::cout << std::endl << "Vector length is: " << vect1->length() << std::endl;
			break;
		case 2:
			try {
				returnObject = vect1->direction();
				if (returnObject) {
				std::cout << std::endl << "The directional vector is: " << *returnObject << std::endl;
				}
			}
			catch (...) {
				std::cout << std::endl << "Exception caught! Vector length is 0 and doesn't have a direction." << std::endl;
			}
			break;
		case 3:
			std::cout << std::endl << "The vector " << (vect1->isZero()? "is a zero vector." : "isn't a zero vector.") << std::endl;
			break;
		case 4:
			inputSecVect(x, y, z);
			vect2 = new Vector(x, y, z);
			try {
				std::cout << "The two vectors are" << (vect1->isParallel(*vect2) ? " " : " not ") << "parallel." << std::endl;
			}
			catch (...) {
				std::cout << "Exception caught! Vector length is 0." << std::endl;
			}

			break;
		case 5:
			inputSecVect(x, y, z);
			vect2 = new Vector(x, y, z);
			try {
				std::cout << std::endl << "The vectors are" << (vect1->isPerpendicular(*vect2) ? " " : " not ") << "perpendicular." << std::endl;
			}
			catch (...) {
				std::cout << std::endl << "Exception caught! Vector length is 0." << std::endl;
			}
			break;
		case 6:
			inputSecVect(x, y, z);
			vect2 = new Vector(x, y, z);
			returnObject = (*vect1 + *vect2);
			std::cout << std::endl << "The result of adding the vectors together is: " << *returnObject << std::endl;
			break;
		case 7:
			inputSecVect(x, y, z);
			vect2 = new Vector(x, y, z);
			returnObject = (*vect1 - *vect2);
			std::cout << std::endl << "The result of subtracting the vectors together is: " << *returnObject << std::endl;
			break;
		case 8:
			std::cout << std::endl << "Enter the number you want to multiply with the vector: ";
			std::cin >> num;
			std::cout << std::endl << "The result is: " << num * (*vect1) << std::endl;
			break;
		case 9: //TODO test this
			inputSecVect(x, y, z);
			vect2 = new Vector(x, y, z);
			std::cout << std::endl << "The scalar product of the vectors is: " << *vect1 * *vect2 << std::endl;
			break;
		case 10:
			inputSecVect(x, y, z);
			vect2 = new Vector(x, y, z);
			returnObject = (*vect1 ^ *vect2);
			std::cout << std::endl << "The vector product of the vectors is: " << *returnObject << std::endl;
			break;
		case 11:
			inputSecVect(x, y, z);
			vect2 = new Vector(x, y, z);
			inputSecVect(x, y, z);
			vect3 = new Vector(x, y, z);
			//num = vect1->operator()(*vect2, *vect3);
			std::cout << std::endl << "The mixed product of the vectors is: " << (*vect1)(*vect2, *vect3) << std::endl;
			break;
		}

		if (vect3 != nullptr) {
			delete vect3;
			vect3 = nullptr;
		}
		if (vect2 != nullptr) {
			delete vect2;
			vect2 = nullptr;
		}
		if (returnObject != nullptr) {
			delete returnObject;
			returnObject = nullptr;
		}

		std::cout << std::endl << "Do you want to select a new operation?(y/n) ";
		cont = inputDataYN();
	} while (cont == 'y');

	return 0;
}

int lineOperation(Element* line1) {
	char cont = 'n';
	int operation;
	double x, y, z, x1, y1, z1;
	bool result = false;
	Element* returnObject = nullptr;
	Element* line2 = nullptr;

	do {
		std::cout << std::endl << "Select an operation from the menu: \n"
			<< "1  - Calculate line direction\n"
			<< "2  - Calculate normal vector\n"
			<< "3  - Calculate angle between lines\n"
			<< "4  - \n"
			<< "5  - Check if two lines are parallel\n"
			<< "6  - Check if two lines match\n";

		operation = inputDataInt(1, 11);
		cont = 'n';
		switch (operation) {
		case 1:
			try {
				returnObject = line1->direction();
				if (returnObject) {
					std::cout << std::endl << "The directional vector of the line is: " << *returnObject << std::endl;
				}
			}
			catch (...) {
				std::cout << std::endl << "Exception caught! Vector length is 0 and doesn't have a direction." << std::endl;
			}
			break;
		case 2:
			returnObject = line1->normal();
			std::cout << std::endl << "Normal vector of  the line is: " << *returnObject << std::endl;
			break;
		case 3:
			std::cout << std::endl << "Enter x, y and z for the point: ";
			std::cin >> x >> y >> z;
			std::cout << std::endl << "Enter x, y and z for the vector: ";
			std::cin >> x1 >> y1 >> z1;

			line2 = new Vector(x1, y1, z1);

			std::cout << std::endl << "The angle between the lines is " << line1->angle(line2) << std::endl;

			break;
		case 4:
			break;
		case 5:
			std::cout << std::endl << "Enter x, y and z for the point: ";
			std::cin >> x >> y >> z;
			std::cout << std::endl << "Enter x, y and z for the vector: ";
			std::cin >> x1 >> y1 >> z1;

			line2 = new Line(Point(x, y, z), Vector(x1, y1, z1));

			std::cout << std::endl << "The two lines are" << ((*line1||*line2)? " ": " not ") << "parallel." << std::endl;
			break;
		case 6:
			std::cout << std::endl << "Enter x, y and z for the point: ";
			std::cin >> x >> y >> z;
			std::cout << std::endl << "Enter x, y and z for the vector: ";
			std::cin >> x1 >> y1 >> z1;

			line2 = new Line(Point(x, y, z), Vector(x1, y1, z1));

			std::cout << std::endl << "The two lines" << ((*line1 == *line2) ? " " : " do not ") << "match." << std::endl;
			break;
		}

		if (returnObject != nullptr) {
			delete returnObject;
			returnObject = nullptr;
		}
		if (line2 != nullptr) {
			delete line2;
			line2 = nullptr;
		}

		std::cout << std::endl << "Do you want to select a new operation?(y/n) ";
		cont = inputDataYN();
	} while (cont == 'y');
	return 0;
}