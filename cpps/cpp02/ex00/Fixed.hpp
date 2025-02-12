#pragma once
#include <iostream>

class Fixed
{
private:
	int 				_value;
	static const int	_bitValue;
public:
	Fixed();
	Fixed(const Fixed &f);
	~Fixed();
	Fixed & operator = (const Fixed &f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

