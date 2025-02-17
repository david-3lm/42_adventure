#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int 				_value;
	static const int	_bitValue = 8;
public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed(const int v);
	Fixed(const float v);
	~Fixed();
	Fixed & operator=(const Fixed &f);
	bool operator<(const Fixed &other)const;
	bool operator<=(const Fixed &other)const;
	bool operator>(const Fixed &other)const;
	bool operator>=(const Fixed &other)const;
	bool operator==(const Fixed &other)const;
	bool operator!=(const Fixed &other)const;

	Fixed operator+(const Fixed &other)const;
	Fixed operator-(const Fixed &other)const;
	Fixed operator*(const Fixed &other)const;
	Fixed operator/(const Fixed &other)const;
	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
