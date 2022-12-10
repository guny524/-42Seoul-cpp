#include <iostream>

#include "Fixed.hpp"


int	main(void)
{
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);
	Fixed		e;
	Fixed		f;

	a = Fixed(1234.4321f);
	e.setRawBits(0x7f7fffff); // 8355839.99609375f
	f.setRawBits(0xff7fffff); // -8355839.99609375f

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "e is " << f << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;

	std::cout << "a is exact " << a.exact() << std::endl;
	std::cout << "b is exact " << b.exact() << std::endl;
	std::cout << "c is exact " << c.exact() << std::endl;
	std::cout << "d is exact " << d.exact() << std::endl;
	std::cout << "e is exact " << e.exact() << std::endl;
	std::cout << "e is exact " << f.exact() << std::endl;

	std::cout << c.getRawBits() << std::endl;

	return 0;
}
