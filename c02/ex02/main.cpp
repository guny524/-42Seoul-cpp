#include <iostream>

#include "Fixed.hpp"


int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << std::endl;

	Fixed	c(1.2f);
	Fixed	d(3.4f);

	std::cout << c << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d << std::endl;
	std::cout << d.getRawBits() << std::endl;

	std::cout << c + d << std::endl;
	std::cout << (c + d).getRawBits() << std::endl;

	std::cout << c - d << std::endl;
	std::cout << (c - d).getRawBits() << std::endl;

	std::cout << c * d << std::endl;
	std::cout << (c * d).getRawBits() << std::endl;

	std::cout << c / d << std::endl;
	std::cout << (c / d).getRawBits() << std::endl;

	std::cout << std::endl << std::endl;

	Fixed	e(-1.2f);
	Fixed	f(-3.4f);

	std::cout << e << std::endl;
	std::cout << e.getRawBits() << std::endl;
	std::cout << f << std::endl;
	std::cout << f.getRawBits() << std::endl;

	std::cout << e + f << std::endl;
	std::cout << (e + f).getRawBits() << std::endl;

	std::cout << e - f << std::endl;
	std::cout << (e - f).getRawBits() << std::endl;

	std::cout << e * f << std::endl;
	std::cout << (e * f).getRawBits() << std::endl;

	std::cout << e / f << std::endl;
	std::cout << (e / f).getRawBits() << std::endl;

	return 0;
}
