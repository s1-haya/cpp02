#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0) { 
}

Fixed::Fixed( int fixedPointNumber ) : fixedPointNumber(fixedPointNumber * (1 << this->fractionalBits)) { 
}

Fixed::Fixed( float fixedPointNumber ) : fixedPointNumber(static_cast<int>(roundf(fixedPointNumber * (1 << this->fractionalBits)))) { 
}

Fixed::Fixed( const Fixed& other ) {
	*this = other;
}

Fixed::~Fixed(){
}

Fixed& Fixed::operator=( const Fixed& other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNumber = other.getRawBits();
	return (*this);
}

bool Fixed::operator==( const Fixed& other ) {
	std::cout << "equality operator called" << std::endl;
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=( const Fixed& other ) {
	std::cout << "not equality operator called" << std::endl;
	return (this->toFloat() != other.toFloat());
}

bool Fixed::operator>( const Fixed& other ) {
	std::cout << "greater than operator called" << std::endl;
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<( const Fixed& other ) {
	std::cout << "less than operator called" << std::endl;
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=( const Fixed& other ) {
	std::cout << "greater than or equal to operator called" << std::endl;
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=( const Fixed& other ) {
	std::cout << "less than or equal to operator called" << std::endl;
	return (this->toFloat() < other.toFloat());
}

Fixed Fixed::operator+( const Fixed& other ) {
	std::cout << "plus operator called" << std::endl;
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-( const Fixed& other ) {
	std::cout << "minus operator called" << std::endl;
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*( const Fixed& other ) {
	std::cout << "multiply operator called" << std::endl;
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/( const Fixed& other ) {
	std::cout << "divide operator called" << std::endl;
	if (other.toInt() == 0)
	{
		std::cerr << "Attempted to divide by zero." << std::endl;
		std::abort();
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++( void ) {
	std::cout << "pre-increment operator called" << std::endl;
	this->fixedPointNumber ++;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	std::cout << "post-increment operator called" << std::endl;
	Fixed tmp = *this;
	this->fixedPointNumber ++;
	return (tmp);
}

Fixed& Fixed::operator--( void ) {
	std::cout << "pre-decrement operator called" << std::endl;
	this->fixedPointNumber --;
	return (*this);
}

Fixed Fixed::operator--( int ) {
	std::cout << "post-decrement operator called" << std::endl;
	Fixed tmp = *this;
	this->fixedPointNumber --;
	return (tmp);
}

int Fixed::toInt( void ) const {
	return (static_cast<int>(this->fixedPointNumber) / (1 << this->fractionalBits));
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(this->fixedPointNumber) / (1 << this->fractionalBits));
}

Fixed& Fixed::min( Fixed& a, Fixed& b ) {
	if (a.toFloat() > b.toFloat())
		return (b);
	return (a);
}

Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
	if (a.toFloat() > b.toFloat())
		return (const_cast<Fixed&>(b));
	return (const_cast<Fixed&>(a));
}

Fixed& Fixed::max( Fixed& a, Fixed& b ) {
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
	if (a.toFloat() >= b.toFloat())
		return (const_cast<Fixed&>(a));
	return (const_cast<Fixed&>(b));
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
