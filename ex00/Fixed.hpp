#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int fixedPointNumber;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy_data);
		Fixed& operator=( const Fixed& other );
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw ); 
};

#endif
