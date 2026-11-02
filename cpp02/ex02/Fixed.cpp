#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int n) : _value(n * (1 << _fractionalBits))
{
}

Fixed::Fixed(const float f) : _value((int)roundf(f * (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_value / (1 << _fractionalBits));
}

/* ---------- comparison ---------- */

bool	Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (_value != other._value);
}

/* ---------- arithmetic ---------- */

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(_value + other._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(_value - other._value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits((int)(((long)_value * other._value) >> _fractionalBits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;

	if (other._value == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return (result);
	}
	result.setRawBits((int)((long)_value * (1 << _fractionalBits) / other._value));
	return (result);
}

/* ---------- increment / decrement ---------- */

Fixed	&Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	_value++;
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	_value--;
	return (old);
}

/* ---------- min / max ---------- */

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
