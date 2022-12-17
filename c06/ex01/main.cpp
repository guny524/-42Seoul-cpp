#include <iostream>
#include <string>

#include "serialize.hpp"


int	main(void)
{
	// local
	Data	d1;

	d1.intWhatever = 42;
	d1.floatWhatever = 42.42f;
	d1.strWhatever = "real whaterver 42";

	std::cout << d1.intWhatever << std::endl;
	std::cout << d1.floatWhatever << std::endl;
	std::cout << d1.strWhatever << std::endl;
	std::cout << &d1 << std::endl;
	std::cout << std::endl;

	uintptr_t	ptr1 = serialize(&d1);
	std::cout << ptr1 << std::endl;
	std::cout << std::endl;

	Data	*rd1 = deserialize(ptr1);
	std::cout << rd1 << std::endl;
	std::cout << rd1->intWhatever << std::endl;
	std::cout << rd1->floatWhatever << std::endl;
	std::cout << rd1->strWhatever << std::endl;
	std::cout << std::endl;


	std::cout << std::endl;


	// new
	Data	*d2 = new Data;

	d2->intWhatever = 42;
	d2->floatWhatever = 42.42f;
	d2->strWhatever = "real wahtever 42";

	std::cout << d2->intWhatever << std::endl;
	std::cout << d2->floatWhatever << std::endl;
	std::cout << d2->strWhatever << std::endl;
	std::cout << d2 << std::endl;
	std::cout << std::endl;

	uintptr_t	ptr2 = serialize(d2);
	std::cout << ptr2 << std::endl;
	std::cout << std::endl;

	Data	*rd2 = deserialize(ptr2);
	std::cout << rd2 << std::endl;
	std::cout << rd2->intWhatever << std::endl;
	std::cout << rd2->floatWhatever << std::endl;
	std::cout << rd2->strWhatever << std::endl;

	return (0);
}
