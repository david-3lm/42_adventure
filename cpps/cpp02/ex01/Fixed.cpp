#include "Fixed.hpp"

//Default constructor that inits the fixed-point number value to 0
Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int v)
{
	std::cout << "Constructor with integer called" << std::endl;
	this->_value = (v << Fixed::_bitValue);
}

Fixed::Fixed(const float v)
{
	std::cout << "Constructor with float called" << std::endl;
	_value = (int)roundf(v * (1 << Fixed::_bitValue));	
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
	{
		this->_value = f.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

//Returns the raw value of the fixed-point number
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return _value;
}

//sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	_value = raw;
}