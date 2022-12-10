#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>
# include <string>

class Fixed
{
private:
	int					_value;
	static const int	_fract_bit = 8;
public:
	Fixed(void);
	Fixed(const Fixed& fixed);
	Fixed(const int& num);
	Fixed(const float& num);
	~Fixed();

	Fixed&	operator=(const Fixed& fixed);
	Fixed&	operator=(const float& num);
	Fixed&	operator=(const int& num);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	std::string	exact(void) const;

	static Fixed&	min(Fixed& fixed1, Fixed& fixed2);
	static Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed&	max(Fixed& fixed1, Fixed& fixed2);
	static Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);

	bool	operator>(const Fixed& fixed);
	bool	operator>(const float& num);
	bool	operator>(const int& num);

	bool	operator<(const Fixed& fixed);
	bool	operator<(const float& num);
	bool	operator<(const int& num);

	bool	operator>=(const Fixed& fixed);
	bool	operator>=(const float& num);
	bool	operator>=(const int& num);

	bool	operator<=(const Fixed& fixed);
	bool	operator<=(const float& num);
	bool	operator<=(const int& num);

	bool	operator==(const Fixed& fixed);
	bool	operator==(const float& num);
	bool	operator==(const int& num);

	bool	operator!=(const Fixed& fixed);
	bool	operator!=(const float& num);
	bool	operator!=(const int& num);

	Fixed	operator+(const Fixed& fixed);
	Fixed	operator+(const float& num);
	Fixed	operator+(const int& num);

	Fixed	operator-(const Fixed& fixed);
	Fixed	operator-(const float& num);
	Fixed	operator-(const int& num);

	Fixed	operator*(const Fixed& fixed);
	Fixed	operator*(const float& num);
	Fixed	operator*(const int& num);

	Fixed	operator/(const Fixed& fixed);
	Fixed	operator/(const float& num);
	Fixed	operator/(const int& num);

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);
};

std::ostream&	operator<<(std::ostream& out, const Fixed &fixed);

bool	operator>(const float &num, const Fixed &fixed);
bool	operator>(const int &num, const Fixed &fixed);

bool	operator<(const float &num, const Fixed &fixed);
bool	operator<(const int &num, const Fixed &fixed);

bool	operator>=(const float &num, const Fixed &fixed);
bool	operator>=(const int &num, const Fixed &fixed);

bool	operator<=(const float &num, const Fixed &fixed);
bool	operator<=(const int &num, const Fixed &fixed);

bool	operator==(const float &num, const Fixed &fixed);
bool	operator==(const int &num, const Fixed &fixed);

bool	operator!=(const float &num, const Fixed &fixed);
bool	operator!=(const int &num, const Fixed &fixed);

Fixed	operator+(const float &num, const Fixed &fixed);
Fixed	operator+(const int &num, const Fixed &fixed);

Fixed	operator-(const float &num, const Fixed &fixed);
Fixed	operator-(const int &num, const Fixed &fixed);

Fixed	operator*(const float &num, const Fixed &fixed);
Fixed	operator*(const int &num, const Fixed &fixed);

Fixed	operator/(const float &num, const Fixed &fixed);
Fixed	operator/(const int &num, const Fixed &fixed);

#endif
