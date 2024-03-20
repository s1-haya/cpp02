#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0) { 
	std::cout << "default constructor called" << std::endl; 
}

Fixed::Fixed( int fixedPointNumber ) : fixedPointNumber(fixedPointNumber * (1 << this->fractionalBits)) { 
	std::cout << "Int constructor called" << std::endl; 
}

Fixed::Fixed( float fixedPointNumber ) : fixedPointNumber(static_cast<int>(roundf(fixedPointNumber * (1 << this->fractionalBits)))) { 
	std::cout << "Float constructor called" << std::endl; 
}

Fixed::Fixed( const Fixed& other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNumber = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "destructor called" << std::endl;
}

int Fixed::toInt( void ) const{
	return (static_cast<int>(this->fixedPointNumber) / (1 << this->fractionalBits));
}

float Fixed::toFloat( void ) const{
	return (static_cast<float>(this->fixedPointNumber) / (1 << this->fractionalBits));
}

int Fixed::getRawBits( void ) const {
	return (this->fixedPointNumber);
}

void Fixed::setRawBits( int const raw ) {
	this->fixedPointNumber = raw;
}

std::ostream& operator<<( std::ostream& os, const Fixed& data ) {
	os << data.toFloat();
	return (os);
}
