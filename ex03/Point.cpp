#include "Point.hpp"

Point::Point()
	: x(0), y(0) {}

Point::~Point(){}

Point::Point( const Fixed x, const Fixed y )
	: x(x), y(y) {}

Point::Point( Point& other ) {
	*this = other;
}

Point& Point::operator=( Point& other ) {
	return (other);
}
