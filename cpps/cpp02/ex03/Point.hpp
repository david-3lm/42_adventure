#pragma once
#include "Fixed.hpp"
class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Point& p);
	Point(const float X, const float Y);
	~Point();
	Point& operator=(const Point& p);

	const Fixed& GetX( void ) const;
	const Fixed& GetY( void ) const;
};

