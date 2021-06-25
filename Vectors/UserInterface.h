#pragma once
#include <iostream>
#include <exception>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Line.h"


#include "UserInterface.h"

int inputDataInt(int x, int y);
char inputDataYN();
int inputSecVect(double&, double&, double&);
int pointOperation(Element*);
int vectorOperation(Element*);
int lineOperation(Element*);
int triangleOperation(Element*);