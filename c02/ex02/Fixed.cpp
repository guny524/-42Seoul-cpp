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
	*this = fixed;
}

Fixed::Fixed(const int& num)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(num << _fract_bit);
}

Fixed::Fixed(const float& num)
{
	std::cout << "Float constructor called" << std::endl;

	int	sign = 1;
	if (num < 0)
		sign = -1;
	// 절댓값
	int	abs = sign * static_cast<int>(num);

	_value = 0;
	if (num < 0)
	{
		int	sign_filter = 0x01 << 31;
		_value |= sign_filter;
	}
	_value |= abs << _fract_bit;


	int		res = 0x00;
	float	fract = num - abs;
	// std::cout << std::endl << num << std::endl << "fract: " << fract << std::endl;
	for (int i=0; i<_fract_bit; ++i)
	{
		res <<= 1;
		fract *= 2;
		if (fract > 1)
		{
			res |= 1;
			fract -= 1;
		}
	}

	_value |= res;
	// setRawBits(int(roundf(num * (1 << _fract_bit))));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called " << std::endl;
	_value = fixed.getRawBits();
	return *this;
}

Fixed&	Fixed::operator=(const float& num)
{
	std::cout << "Copy assignment operator called " << std::endl;
	Fixed f = Fixed(num);
	_value = f.getRawBits();
	return *this;
}

Fixed&	Fixed::operator=(const int& num)
{
	std::cout << "Copy assignment operator called " << std::endl;
	Fixed f = Fixed(num);
	_value = f.getRawBits();
	return *this;
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	else
		return (fixed2);
}

Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1._value < fixed2._value)
		return (const_cast<Fixed&>(fixed1));
	else
		return (const_cast<Fixed&>(fixed2));
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed2);
	else
		return (fixed1);
}

Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1._value < fixed2._value)
		return (const_cast<Fixed&>(fixed2));
	else
		return (const_cast<Fixed&>(fixed1));
}

bool	Fixed::operator>(const Fixed& fixed)
{
	return (this->_value > fixed._value);
}

bool	Fixed::operator>(const float& num)
{
	return (this->_value > Fixed(num).getRawBits());
}

bool	Fixed::operator>(const int& num)
{
	return (this->_value > num);
}


bool	Fixed::operator<(const Fixed& fixed)
{
	return (this->_value < fixed._value);
}

bool	Fixed::operator<(const float& num)
{
	return (this->_value < Fixed(num).getRawBits());
}

bool	Fixed::operator<(const int& num)
{
	return (this->_value < num);
}


bool	Fixed::operator>=(const Fixed& fixed)
{
	return (this->_value >= fixed._value);
}

bool	Fixed::operator>=(const float& num)
{
	return (this->_value >= Fixed(num).getRawBits());
}

bool	Fixed::operator>=(const int& num)
{
	return (this->_value >= num);
}


bool	Fixed::operator<=(const Fixed& fixed)
{
	return (this->_value <= fixed._value);
}

bool	Fixed::operator<=(const float& num)
{
	return (this->_value <= Fixed(num).getRawBits());
}

bool	Fixed::operator<=(const int& num)
{
	return (this->_value <= num);
}


bool	Fixed::operator==(const Fixed& fixed)
{
	return (this->_value == fixed._value);
}

bool	Fixed::operator==(const float& num)
{
	return (this->_value == Fixed(num).getRawBits());
}

bool	Fixed::operator==(const int& num)
{
	return (this->_value == num);
}


bool	Fixed::operator!=(const Fixed& fixed)
{
	return (this->_value != fixed._value);
}

bool	Fixed::operator!=(const float& num)
{
	return (this->_value != Fixed(num).getRawBits());
}

bool	Fixed::operator!=(const int& num)
{
	return (this->_value != num);
}


Fixed	Fixed::operator+(const Fixed& fixed)
{
	Fixed	ret;

	ret.setRawBits(this->_value + fixed._value);
	return (ret);
}

Fixed	Fixed::operator+(const float& num)
{
	return (*this + Fixed(num));
}

Fixed	Fixed::operator+(const int& num)
{
	return (*this + Fixed(num));
}


Fixed	Fixed::operator-(const Fixed& fixed)
{
	Fixed	ret;

	ret.setRawBits(this->_value - fixed._value);
	return (ret);
}

Fixed	Fixed::operator-(const float& num)
{
	return (*this - Fixed(num));
}

Fixed	Fixed::operator-(const int& num)
{
	return (*this - Fixed(num));
}


Fixed	Fixed::operator*(const Fixed& fixed)
{
	Fixed	ret;

	ret.setRawBits(this->_value * fixed._value);
	ret._value >>= ret._fract_bit;
	return (ret);
}

Fixed	Fixed::operator*(const float& num)
{
	Fixed	ret;

	ret = *this * Fixed(num);
	ret._value >>= ret._fract_bit;
	return (ret);
}

Fixed	Fixed::operator*(const int& num)
{
	Fixed	ret;

	ret = *this * Fixed(num);
	ret._value >>= ret._fract_bit;
	return (ret);
}


Fixed	Fixed::operator/(const Fixed& fixed)
{
	Fixed	ret;

	ret.setRawBits(this->_value / fixed._value);
	ret._value <<= ret._fract_bit;
	return (ret);
}

Fixed	Fixed::operator/(const float& num)
{
	Fixed	ret;

	ret = *this / Fixed(num);
	ret._value <<= ret._fract_bit;
	return (ret);
}

Fixed	Fixed::operator/(const int& num)
{
	Fixed	ret;

	ret = *this / Fixed(num);
	ret._value <<= ret._fract_bit;
	return (ret);
}


Fixed&	Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);

	this->_value++;
	return (ret);
}

Fixed&	Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);

	this->_value--;
	return (ret);
}


int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (Fixed::toInt() + Fixed::extractFloat());

	// return (float(this->getRawBits()) / (1 << _fract_bit));
}

int	Fixed::toInt(void) const
{
	// extract sign
	int	sign_filter = 0x01 << 31;
	int sign = _value & sign_filter;
	if (sign)
		sign = -1;
	else
		sign = 1;

	// extract integer
	int	integer_filter = 0x00;
	for (int i=0; i<32-_fract_bit - 1; ++i)
	{
		integer_filter <<= 1;
		integer_filter |= 1;
	}
	int	integer = (_value & (integer_filter << _fract_bit)) >> _fract_bit;

	return (sign * integer);

	// return (int(this->getRawBits()) / (1 << _fract_bit));
}

std::ostream& operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();

	return out;
}

float	Fixed::extractFloat(void) const
{
	int	fract_filter = 0x00;
	for (int i=0; i<_fract_bit; ++i)
	{
		fract_filter <<= 1;
		fract_filter |= 1;
	}

	float	res = 0;
	int		fract = (_value & fract_filter);
	// std::cout << std::endl << "fract: " << fract << std::endl;
	for (int i=0; i<_fract_bit; ++i)
	{
		if (fract & 0x01)
		{
			// std::cout << "add: " << 1.0 / (1 << (_fract_bit - i)) << std::endl;
			res += 1.0 / (1 << (_fract_bit - i));
		}
		fract >>= 1;
	}

	return (res);
}

std::string	Fixed::exact(void) const
{
	float	fl = extractFloat();
	std::stringstream	st;
	st << fl;
	std::string			fract = st.str();

	if (fl != 0)
		fract = fract.substr(2, fract.size());

	std::stringstream	ret;
	ret << toInt() << "." << fract;

	return ret.str();
}
