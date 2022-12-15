#include "Point.hpp"

#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	ab = a - b;
	Point	bc = b - c;
	Point	ca = c - a;
	Point	pb = point - b;
	Point	pc = point - c;
	Point	pa = point - a;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "p: " << point << std::endl;

	std::cout << "ab: " << ab << std::endl;
	std::cout << "bc: " << bc << std::endl;
	std::cout << "ca: " << ca << std::endl;

	std::cout << "ab * pb: " << ab * pb << std::endl;
	std::cout << "bc * pc: " << bc * pc << std::endl;
	std::cout << "ca * pa: " << ca * pa << std::endl;

	bool	aBool = ab * pb > 0;
	bool	bBool = bc * pc > 0;
	bool	cBool = ca * pa > 0;

	if (aBool == bBool && bBool == cBool)
		return (true);
	else
		return (false);
}
