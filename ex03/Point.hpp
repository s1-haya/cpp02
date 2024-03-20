#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point( const Fixed x, const Fixed y );
		Point( Point& other );
		Point& operator=( Point& other );
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
