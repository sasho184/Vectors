#include "Exceptions.h"

VectorLengthException::VectorLengthException():exception() {

}

std::ostream& VectorLengthException::rep(std::ostream& out) {
	out << "Vector length must be greater than 0! ";
	return out;
}