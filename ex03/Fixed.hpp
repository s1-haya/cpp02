#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>

class Fixed{
	private:
		int fixedPointNumber;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed( int fixedPointNumber );
		Fixed( float fixedPointNumber );
		Fixed( const Fixed& other );
		~Fixed();
		Fixed& operator=( const Fixed& other );
		bool operator==( const Fixed& other );
		bool operator!=( const Fixed& other );
		bool operator>( const Fixed& other );
		bool operator<( const Fixed& other );
		bool operator>=( const Fixed& other );
		bool operator<=( const Fixed& other );
		Fixed operator+( const Fixed& other );
		Fixed operator-( const Fixed& other );
		Fixed operator*( const Fixed& other );
		Fixed operator/( const Fixed& other );
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		static Fixed& min( Fixed& a, Fixed& b );
		static Fixed& min( const Fixed& a, const Fixed& b );
		static Fixed& max( Fixed& a, Fixed& b );
		static Fixed& max( const Fixed& a, const Fixed& b );
		int toInt( void ) const;
		float toFloat( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw ); 
};

std::ostream& operator<<( std::ostream& os, const Fixed& data );

#endif
