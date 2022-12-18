#include <iostream>
#include <string>

#include "iter.hpp"


int main(void)
{
	int arr1[3] = {1234, 42, 0};
	iter(arr1, 3, &print);
	std::cout << std::endl;

	const int arr2[3] = {1234, 42, 0};
	iter(arr2, 3, &print);
	std::cout << std::endl;

	const float arr4[3] = {3.14f, 42.42, 1.1111};
	iter(arr4, 3, &print);
	std::cout << std::endl;

	const std::string arr5[3] = {"Hello ", "world", "This is!!"};
	iter(arr5, 3, &print);
	std::cout << std::endl;

	// // TODO remove
	// int	tab[] = {0, 1, 2, 3, 4};
	// Awesome	tab2[5];

	// iter(tab, 5, print);
	// iter(tab2, 5, print);

	return (0);
}
