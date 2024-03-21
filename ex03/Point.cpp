#include "Point.hpp"

Point::Point()
	: x(0), y(0) {}

Point::~Point(){}

Point::Point( const float& x, const float& y )
	: x(Fixed(x)), y(Fixed(y)) {}

Point::Point( const Point& other )
	: x(other.x), y(other.y) {}

Point& Point::operator=( const Point& other ) {
	if (this != &other)
	{
		(Fixed)this->x = other.getX();
		(Fixed)this->y = other.getY();
	}
	return (*this);
}

Fixed Point::getX() const {
	return (this->x);
}

Fixed Point::getY() const {
	return (this->y);
}
