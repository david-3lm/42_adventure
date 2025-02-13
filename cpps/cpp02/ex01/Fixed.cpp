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

Fixed::Fixed(const int v) : _value(v)
{
	std::cout << "Constructor with integer called" << std::endl;
}

Fixed::Fixed(const float v)
{
	std::cout << "Constructor with float called" << std::endl;
	_value = roundf(v);	
}

std::ostream &Fixed::operator<<(std::ostream& ostr, const Fixed& f)
{
	ostr << f.toFloat();
	return (ostr);
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _bitValue);
}

int Fixed::toInt(void) const
{
	return (_value);
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
