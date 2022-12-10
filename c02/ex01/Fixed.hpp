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

	float		extractFloat(void) const;
	std::string	exact(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);

#endif
