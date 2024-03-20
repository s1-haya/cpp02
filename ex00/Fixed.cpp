#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0) { 
	std::cout << "default constructor called" << std::endl; 
}

Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNumber = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return (this->fixedPointNumber);
}

void Fixed::setRawBits( int const raw ) {
	this->fixedPointNumber = raw;
}
