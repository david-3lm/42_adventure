#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int 				_value;
	static const int	_bitValue;
public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(const int v);
	Fixed(const float v);
	~Fixed();
	Fixed & operator = (const Fixed &f);
	std::ostream &operator<<(std::ostream ostr);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;
};

