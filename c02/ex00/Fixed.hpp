#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed
{
private:
	int					_num;
	static const int	fract_bit = 8;
public:
	Fixed(void);
	Fixed(const Fixed& f);
	~Fixed();

	Fixed&	operator=(const Fixed& f);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
