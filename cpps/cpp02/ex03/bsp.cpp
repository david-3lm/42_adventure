#include "Point.hpp"

float area( const Point& a, const Point& b, const Point& c)
{
	float x1, y1;
	float x2, y2;
	float x3, y3;
	float area;
	
	x1 = a.GetX().toFloat();
	y1 = a.GetY().toFloat();
	x2 = b.GetX().toFloat();
	y2 = b.GetY().toFloat();
	x3 = c.GetX().toFloat();
	y3 = c.GetY().toFloat();
	
	// To calculate the area of a triangle given three points:
	// A = (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|
	area = (std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))) / 2.0f;
	return ( area );
}
 
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float A = area(a, b, c);

	float a1 = area(point, b, c);

	float a2 = area(a, point, c);

	float a3 = area(a, b, point);

	return (A == (a1 + a2 + a3));
}