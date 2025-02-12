#include "Fixed.hpp"

const int Fixed::_bitValue = 8;

//Default constructor that inits the fixed-point number value to 0
Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &f) : _value(f._value)
{
	std::cout << "Copy constructor called" << std::endl;
}
//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
//Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
	{
		_value = f._value;
	}
	return *this;
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
