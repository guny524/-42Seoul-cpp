#include <iostream>

#include "Fixed.hpp"


int	main(void)
{
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// std::cout << c.getRawBits() << std::endl;

	// ///////////////////////////////
	// std::cout << std::endl << std::endl << std::endl;

	// std::cout << a.exact() << std::endl;
	// std::cout << b.exact() << std::endl;
	// std::cout << c.exact() << std::endl;
	// std::cout << d.exact() << std::endl;

	// Fixed	e;
	// Fixed	f;
	// Fixed	g(-1.2f);
	// Fixed	h(-3.4f);

	// e.setRawBits(0x7f7fffff); // 8355839.99609375f
	// f.setRawBits(0x808000FF); // -8355839.99609375f

	// std::cout << "e is " << e << std::endl;
	// std::cout << "f is " << f << std::endl;
	// std::cout << "g is " << g << std::endl;
	// std::cout << "h is " << h << std::endl;

	// std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	// std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	// std::cout << "g is " << g.toInt() << " as integer" << std::endl;
	// std::cout << "h is " << h.toInt() << " as integer" << std::endl;

	// std::cout << e.exact() << std::endl;
	// std::cout << f.exact() << std::endl;
	// std::cout << g.exact() << std::endl;
	// std::cout << h.exact() << std::endl;

	return 0;
}
