#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"


int	main(void)
{
	size_t	size = 100;
	int		arrInt[size];

	for (size_t i=0; i<size; ++i)
		arrInt[i] = i;

	std::vector<int>	vectorInt(arrInt, arrInt + size);
	std::list<int>		listInt(arrInt, arrInt + size);
	std::deque<int>		dequeInt(arrInt, arrInt + size);

	std::vector<int>::iterator	vectorIterInt = easyfind(vectorInt, size - 1);
	std::list<int>::iterator	listIterInt = easyfind(listInt, size - 1);
	std::deque<int>::iterator	dequeIterInt = easyfind(dequeInt, size - 1);

	if (vectorIterInt == vectorInt.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *vectorIterInt << std::endl;
	if (listIterInt == listInt.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *listIterInt << std::endl;
	if (dequeIterInt == dequeInt.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *dequeIterInt << std::endl;


	vectorIterInt = easyfind(vectorInt, -2);
	listIterInt = easyfind(listInt, -2);
	dequeIterInt = easyfind(dequeInt, -2);

	if (vectorIterInt == vectorInt.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *vectorIterInt << std::endl;
	if (listIterInt == listInt.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *listIterInt << std::endl;
	if (dequeIterInt == dequeInt.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *dequeIterInt << std::endl;

	std::cout << std::endl;
	////////////////////////////////////////////////////

	float		arrFloat[size];

	for (size_t i=0; i<size; ++i)
		arrFloat[i] = static_cast<float>(i) / 5.2;

	std::vector<float>		vectorFloat(arrFloat, arrFloat + size);
	std::list<float>		listFloat(arrFloat, arrFloat + size);
	std::deque<float>		dequeFloat(arrFloat, arrFloat + size);

	std::vector<float>::iterator	vectorIterFloat = easyfind(vectorFloat, 50.0 / 5.2);
	std::list<float>::iterator	listIterFloat = easyfind(listFloat, 50.0 / 5.2);
	std::deque<float>::iterator	dequeIterFloat = easyfind(dequeFloat, 50.0 / 5.2);

	if (vectorIterFloat == vectorFloat.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *vectorIterFloat << std::endl;
	if (listIterFloat == listFloat.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *listIterFloat << std::endl;
	if (dequeIterFloat == dequeFloat.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *dequeIterFloat << std::endl;


	vectorIterFloat = easyfind(vectorFloat, -2);
	listIterFloat = easyfind(listFloat, -2);
	dequeIterFloat = easyfind(dequeFloat, -2);

	if (vectorIterFloat == vectorFloat.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *vectorIterFloat << std::endl;
	if (listIterFloat == listFloat.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *listIterFloat << std::endl;
	if (dequeIterFloat == dequeFloat.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << *dequeIterFloat << std::endl;

	return (0);
}
