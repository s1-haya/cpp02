#include "Fixed.hpp"

void assert(bool assert){
	if (assert)
		std::cout << "\x1B[32mOK\033[0m\t\t" << std::endl;
	else
		std::cout << "\x1B[31mKO\033[0m\t\t" << std::endl;
}

void testEqualityOperator(){
	Fixed a;
	Fixed b;
	assert(a == b);
}

void testNotEqualityOperator(){
	Fixed a;
	Fixed b;
	a.setRawBits(6);
	assert(a != b);
}

void testGreaterThanOperator(){
	Fixed a;
	Fixed b;
	a.setRawBits(6);
	assert(a > b);
}

void testGreaterThanToEqualToOperator(){
	Fixed a;
	Fixed b;
	a.setRawBits(6);
	assert(a >= b);
}

void testLessThanOperator(){
	Fixed a;
	Fixed b;
	b.setRawBits(6);
	assert(a < b);
}

void testLessThanToEqualToOperator(){
	Fixed a;
	Fixed b;
	b.setRawBits(6);
	assert(a <= b);
}

void testPlusOperator(){
	Fixed a(6);
	Fixed b(3);
	Fixed result = a + b;
	std::cout << a << " + " << b << " = " << result << std::endl;
}

void testMinusOperator(){
	Fixed a(6);
	Fixed b(3);
	Fixed result = a - b;
	std::cout << a << " - " << b << " = " << result << std::endl;
}

void testMultiplyOperator(){
	Fixed a(6);
	Fixed b(3);
	Fixed result = a * b;
	std::cout << a << " * " << b << " = " << result << std::endl;
}

void testDivideOperator(){
	Fixed a(6);
	Fixed b(3);
	Fixed result = a / b;
	std::cout << a << " / " << b << " = " << result << std::endl;
	// b.setRawBits(0);
	// result = a / b;
	// std::cout << a << " / " << b << " = " << result << std::endl;
}

void testIncrementOperator(){
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

void testDecrementOperator(){
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
}

void runTest()
{
	testEqualityOperator();
	testNotEqualityOperator();
	testGreaterThanOperator();
	testGreaterThanToEqualToOperator();
	testLessThanOperator();
	testLessThanToEqualToOperator();
	testPlusOperator();
	testMinusOperator();
	testMultiplyOperator();
	testDivideOperator();
	testIncrementOperator();
	testDecrementOperator();
}
