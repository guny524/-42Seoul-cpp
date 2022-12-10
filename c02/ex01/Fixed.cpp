#include <iostream>
#include <sstream>

#include "Fixed.hpp"

Fixed::Fixed(void):
_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &fixed)
		setRawBits(fixed.getRawBits());
}

Fixed::Fixed(const int& num)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(num << _fract_bit);
}

Fixed::Fixed(const float& num)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(static_cast<int>(num * (1 << _fract_bit)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &fixed)
		setRawBits(fixed.getRawBits());
	return *this;
}

Fixed&	Fixed::operator=(const float& num)
{
	std::cout << "Copy assignment operator called " << std::endl;
	setRawBits(Fixed(num).getRawBits());
	return *this;
}

Fixed&	Fixed::operator=(const int& num)
{
	std::cout << "Copy assignment operator called " << std::endl;
	setRawBits(Fixed(num).getRawBits());
	return *this;
}

int		Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / (1 << _fract_bit));
}

int	Fixed::toInt(void) const
{
	// in case of negative number, don't do shift.
	return (getRawBits() / (1 << _fract_bit));
}

std::ostream& operator<<(std::ostream &out, const Fixed& fixed)
{
	return out << fixed.toFloat();
}

std::string	Fixed::exact(void) const
{
	// extract fraction part
	int	fract_filter = 0x00;
	for (int i=0; i<_fract_bit; ++i)
	{
		fract_filter <<= 1;
		fract_filter |= 1;
	}

	// sum fraction part
	float	fractSum = 0;
	int		fract = (getRawBits() & fract_filter);
	// std::cout << std::endl << "fract: " << fract << std::endl;
	for (int i=0; i<_fract_bit; ++i)
	{
		if (fract & 0x01)
		{
			// std::cout << "add: " << 1.0 / (1 << (_fract_bit - i)) << std::endl;
			fractSum += 1.0 / (1 << (_fract_bit - i));
		}
		fract >>= 1;
	}

	std::stringstream	st;
	st << fractSum;
	std::string			fractStr = st.str();

	if (fractSum != 0)
		fractStr = fractStr.substr(2, fractStr.size());

	std::stringstream	ret;
	ret << toInt() << "." << fractStr;

	return ret.str();
}
