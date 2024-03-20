#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int fixedPointNumber;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed( int fixedPointNumber );
		Fixed( float fixedPointNumber );
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );
		~Fixed();
		int toInt( void ) const;
		float toFloat( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw ); 
};

std::ostream& operator<<( std::ostream& os, const Fixed& data );

#endif
