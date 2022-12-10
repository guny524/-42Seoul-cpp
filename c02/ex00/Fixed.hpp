#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed
{
private:
	int					_value;
	static const int	_fract_bit = 8;
public:
	Fixed(void);
	Fixed(const Fixed& fixed);
	~Fixed();

	Fixed&	operator=(const Fixed& fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
