#include "PmergeMe.hpp"
#include <iostream>


int main(const int argc, const char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: no args" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe	pmergeme(argc - 1, &argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
