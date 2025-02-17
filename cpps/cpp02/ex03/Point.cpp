#include "Point.hpp"

Point::Point() : x(0), y(0) { }

Point::Point(const Point &p) : x(p.x), y(p.y) { }

Point::Point(const float X, const float Y) : x(Fixed(X)), y(Fixed(Y)) {}

Point::~Point() {}

Point &Point::operator=(const Point &p)
{
	if (this != &p)
	{
		*this = Point(p);
	}
	return (*this);
}

const Fixed& Point::GetX(void) const
{
	return this->x;
}

const Fixed& Point::GetY(void) const
{
	return this->y;
}
