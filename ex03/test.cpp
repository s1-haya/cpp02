#include "Fixed.hpp"
#include "Point.hpp"

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
	Fixed a(2.2f);
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

void testBSP(){
	Point a(-2, 1);
	Point b(0, 2);
	Point c(0, -1);
	Point p(-0.9f, 1);

	std::cout << "a: x " << a.getX().toFloat() << ", y " << a.getY().toFloat() << std::endl;
	std::cout << "b: x " << b.getX().toFloat() << ", y " << b.getY().toFloat() << std::endl;
	std::cout << "c: x " << c.getX().toFloat() << ", y " << c.getY().toFloat() << std::endl;
	std::cout << "p: x " << p.getX().toFloat() << ", y " << p.getY().toFloat() << std::endl;
	assert(bsp(a, b, c, p));
}

void runTest()
{
	testBSP();
	// testEqualityOperator();
	// testNotEqualityOperator();
	// testGreaterThanOperator();
	// testGreaterThanToEqualToOperator();
	// testLessThanOperator();
	// testLessThanToEqualToOperator();
	// testPlusOperator();
	// testMinusOperator();
	// testMultiplyOperator();
	// testDivideOperator();
	// testIncrementOperator();
	// testDecrementOperator();
}
