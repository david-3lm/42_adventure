#include "Fixed.hpp"

//Default constructor that inits the fixed-point number value to 0
Fixed::Fixed() : _value(0) 
{
}

//Copy constructor
Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::Fixed(const int v)
{
	this->_value = (v << Fixed::_bitValue);
}

Fixed::Fixed(const float v)
{
	_value = (int)roundf(v * (1 << Fixed::_bitValue));	
}

//Destructor
Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(1 << Fixed::_bitValue);
}

int Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_bitValue);
}


//Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
	{
		this->_value = f._value;
	}
	return *this;
}


bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed r;

	r.setRawBits(this->getRawBits() + other.getRawBits());
	return r;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed r;

	r.setRawBits(this->getRawBits() - other.getRawBits());
	return r;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed r;

	r.setRawBits((this->getRawBits() * other.getRawBits()) >> Fixed::_bitValue);
	return r;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed r;

	r.setRawBits(this->getRawBits() / other.getRawBits());
	return r;
}

//prefix operator

Fixed& Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

//postfix operator

Fixed Fixed::operator++(int)
{
	Fixed curr(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (curr);
}

Fixed Fixed::operator--(int)
{
	Fixed curr(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (curr);
}

//MIN AND MAX

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}


std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

//Returns the raw value of the fixed-point number
int Fixed::getRawBits(void) const
{
	return _value;
}

//sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}
