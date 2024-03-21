#include "Point.hpp"

Fixed clossProduct(Point const a, Point const b, Point const c) {
	return (Fixed((a.getX() - b.getX()) * (c.getY() - b.getY()) - (c.getX() - b.getX()) * (a.getY() - b.getY())));
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
	Fixed d1 = clossProduct(p, a, b);
	Fixed d2 = clossProduct(p, b, c);
	Fixed d3 = clossProduct(p, c, a);
	if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
		return (true);
	return (false);
}
