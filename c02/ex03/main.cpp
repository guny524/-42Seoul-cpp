#include <iostream>

#include "Point.hpp"


int main( void )
{
	Point	a(0, 0);
	Point	b(2, 0);
	Point	c(0, 2);
	Point	p(0.5, 0.5);

	std::cout << bsp(a, b, c, p) << std::endl;

	p = Point(1, 1);
	std::cout << bsp(a, b, c, p) << std::endl;

	p = Point(1, 2);
	std::cout << bsp(a, b, c, p) << std::endl;

	return 0;
}
