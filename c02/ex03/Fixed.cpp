#include <iostream>
#include <sstream>

#include "Fixed.hpp"

Fixed::Fixed(void):
_value(0)
{}

Fixed::Fixed(const Fixed& fixed)
{
	if (this != &fixed)
		setRawBits(fixed.getRawBits());
}

Fixed::Fixed(const int& num)
{
	setRawBits(num << _fract_bit);
}

Fixed::Fixed(const float& num)
{
	setRawBits(static_cast<int>(num * (1 << _fract_bit)));
}

Fixed::~Fixed(void)
{}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
		setRawBits(fixed.getRawBits());
	return *this;
}

Fixed&	Fixed::operator=(const float& num)
{
	setRawBits(Fixed(num).getRawBits());
	return *this;
}

Fixed&	Fixed::operator=(const int& num)
{
	setRawBits(Fixed(num).getRawBits());
	return *this;
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
	return (static_cast<float>(getRawBits()) / (1 << _fract_bit));
}

int	Fixed::toInt(void) const
{
	// in case of negative number, don't do shift.
	return (getRawBits() / (1 << _fract_bit));
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
	for (int i=0; i<_fract_bit; ++i)
	{
		if (fract & 0x01)
		{
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

std::ostream& operator<<(std::ostream &out, const Fixed& fixed)
{
	return out << fixed.toFloat();
}



Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	else
		return (fixed2);
}

Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (const_cast<Fixed&>(fixed1));
	else
		return (const_cast<Fixed&>(fixed2));
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed2);
	else
		return (fixed1);
}

Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (const_cast<Fixed&>(fixed2));
	else
		return (const_cast<Fixed&>(fixed1));
}

bool	Fixed::operator>(const Fixed& fixed)
{
	return (getRawBits() > fixed.getRawBits());
}

bool	Fixed::operator>(const float& num)
{
	return (getRawBits() > Fixed(num).getRawBits());
}

bool	Fixed::operator>(const int& num)
{
	return (getRawBits() > num);
}


bool	Fixed::operator<(const Fixed& fixed)
{
	return (getRawBits() < fixed.getRawBits());
}

bool	Fixed::operator<(const float& num)
{
	return (getRawBits() < Fixed(num).getRawBits());
}

bool	Fixed::operator<(const int& num)
{
	return (getRawBits() < num);
}


bool	Fixed::operator>=(const Fixed& fixed)
{
	return (getRawBits() >= fixed.getRawBits());
}

bool	Fixed::operator>=(const float& num)
{
	return (getRawBits() >= Fixed(num).getRawBits());
}

bool	Fixed::operator>=(const int& num)
{
	return (getRawBits() >= num);
}


bool	Fixed::operator<=(const Fixed& fixed)
{
	return (getRawBits() <= fixed.getRawBits());
}

bool	Fixed::operator<=(const float& num)
{
	return (getRawBits() <= Fixed(num).getRawBits());
}

bool	Fixed::operator<=(const int& num)
{
	return (getRawBits() <= num);
}


bool	Fixed::operator==(const Fixed& fixed)
{
	return (getRawBits() == fixed.getRawBits());
}

bool	Fixed::operator==(const float& num)
{
	return (getRawBits() == Fixed(num).getRawBits());
}

bool	Fixed::operator==(const int& num)
{
	return (getRawBits() == num);
}


bool	Fixed::operator!=(const Fixed& fixed)
{
	return (getRawBits() != fixed.getRawBits());
}

bool	Fixed::operator!=(const float& num)
{
	return (getRawBits() != Fixed(num).getRawBits());
}

bool	Fixed::operator!=(const int& num)
{
	return (getRawBits() != num);
}


Fixed	Fixed::operator+(const Fixed& fixed)
{
	Fixed	ret;

	ret.setRawBits(getRawBits() + fixed.getRawBits());
	return (ret);
}

Fixed	Fixed::operator+(const float& num)
{
	Fixed	ret;

	ret.setRawBits(getRawBits() + Fixed(num).getRawBits());
	return (ret);
}

Fixed	Fixed::operator+(const int& num)
{
	Fixed	ret;

	ret.setRawBits(getRawBits() + Fixed(num).getRawBits());
	return (ret);
}


Fixed	Fixed::operator-(const Fixed& fixed)
{
	Fixed	ret;

	ret.setRawBits(getRawBits() - fixed.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(const float& num)
{
	Fixed	ret;

	ret.setRawBits(getRawBits() - Fixed(num).getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(const int& num)
{
	Fixed	ret;

	ret.setRawBits(getRawBits() - Fixed(num).getRawBits());
	return (ret);
}


Fixed	Fixed::operator*(const Fixed& fixed)
{
	Fixed	ret;

	ret.setRawBits((getRawBits() * fixed.getRawBits()) >> ret._fract_bit);
	return (ret);
}

Fixed	Fixed::operator*(const float& num)
{
	Fixed	ret;

	ret.setRawBits((getRawBits() * Fixed(num).getRawBits()) >> ret._fract_bit);
	return (ret);
}

Fixed	Fixed::operator*(const int& num)
{
	Fixed	ret;

	ret.setRawBits((getRawBits() * Fixed(num).getRawBits()) >> ret._fract_bit);
	return (ret);
}


Fixed	Fixed::operator/(const Fixed& fixed)
{
	if (fixed.getRawBits() == 0)
	{
		std::cerr << "Divide by zero !!" << std::endl;
		return (Fixed(0));
	}

	Fixed	ret;

	ret.setRawBits((getRawBits() << _fract_bit) / fixed.getRawBits());
	return (ret);
}

Fixed	Fixed::operator/(const float& num)
{
	if (num == 0)
	{
		std::cerr << "Divide by zero !!" << std::endl;
		return (Fixed(0));
	}

	Fixed	ret;

	ret.setRawBits((getRawBits() << _fract_bit) / Fixed(num).getRawBits());
	return (ret);
}

Fixed	Fixed::operator/(const int& num)
{
	if (num == 0)
	{
		std::cerr << "Divide by zero !!" << std::endl;
		return (Fixed(0));
	}

	Fixed	ret;

	ret.setRawBits((getRawBits() << _fract_bit) / Fixed(num).getRawBits());
	return (ret);
}


Fixed&	Fixed::operator++(void)
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);

	setRawBits(getRawBits() + 1);
	return (ret);
}

Fixed&	Fixed::operator--(void)
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);

	setRawBits(getRawBits() - 1);
	return (ret);
}


bool	operator>(const float &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() > fixed.getRawBits());
}

bool	operator>(const int &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() > fixed.getRawBits());
}


bool	operator<(const float &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() < fixed.getRawBits());
}

bool	operator<(const int &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() < fixed.getRawBits());
}


bool	operator>=(const float &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() >= fixed.getRawBits());
}

bool	operator>=(const int &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() >= fixed.getRawBits());
}


bool	operator<=(const float &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() <= fixed.getRawBits());
}

bool	operator<=(const int &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() <= fixed.getRawBits());
}


bool	operator==(const float &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() == fixed.getRawBits());
}

bool	operator==(const int &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() == fixed.getRawBits());
}


bool	operator!=(const float &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() != fixed.getRawBits());
}

bool	operator!=(const int &num, const Fixed &fixed)
{
	return (Fixed(num).getRawBits() != fixed.getRawBits());
}


Fixed	operator+(const float &num, const Fixed &fixed)
{
	Fixed	ret;

	ret.setRawBits(Fixed(num).getRawBits() + fixed.getRawBits());
	return (ret);
}

Fixed	operator+(const int &num, const Fixed &fixed)
{
	Fixed	ret;

	ret.setRawBits(Fixed(num).getRawBits() + fixed.getRawBits());
	return (ret);
}


Fixed	operator-(const float &num, const Fixed &fixed)
{
	Fixed	ret;

	ret.setRawBits(Fixed(num).getRawBits() - fixed.getRawBits());
	return (ret);
}

Fixed	operator-(const int &num, const Fixed &fixed)
{
	Fixed	ret;

	ret.setRawBits(Fixed(num).getRawBits() - fixed.getRawBits());
	return (ret);
}


Fixed	operator*(const float &num, const Fixed &fixed)
{
	Fixed	ret;

	ret.setRawBits(Fixed(num).getRawBits() * fixed.getRawBits());
	return (ret);
}

Fixed	operator*(const int &num, const Fixed &fixed)
{
	Fixed	ret;

	ret.setRawBits(Fixed(num).getRawBits() * fixed.getRawBits());
	return (ret);
}


Fixed	operator/(const float &num, const Fixed &fixed)
{
	Fixed	ret;

	ret.setRawBits(Fixed(num).getRawBits() / fixed.getRawBits());
	return (ret);
}

Fixed	operator/(const int &num, const Fixed &fixed)
{
	Fixed	ret;

	ret.setRawBits(Fixed(num).getRawBits() / fixed.getRawBits());
	return (ret);
}

Fixed	operator*(const Fixed &fixed1, const Fixed &fixed2)
{
	Fixed	ret;

	ret.setRawBits(fixed1.getRawBits() * fixed2.getRawBits());
	return (ret);
}

Fixed	operator-(const Fixed &fixed1, const Fixed &fixed2)
{
	Fixed	ret;

	ret.setRawBits(fixed1.getRawBits() - fixed2.getRawBits());
	return (ret);
}
