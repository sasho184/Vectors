#include <exception>
#include <iostream>

class VectorLengthException: 
	public std::exception 
{
public:
	VectorLengthException();
	std::ostream& rep(std::ostream&);
};