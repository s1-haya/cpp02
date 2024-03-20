#include "Fixed.hpp"


int main(void)
{
	Fixed fix;
	std::cout << fix.getRawBits() << std::endl;
	Fixed fix2(fix);
	std::cout << fix.getRawBits() << std::endl;
	// this can implent because definition operator!
	fix = fix2;
	fix2.setRawBits(1);
	std::cout << fix.getRawBits() << std::endl;
	return (0);
}
