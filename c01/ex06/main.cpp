#include <iostream>
#include <string>

#include "Harl.hpp"


int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "argumnet count is not 2" << std::endl;
		return (1);
	}

	std::string	input(argv[1]);
	Harl	h;

	std::string	arr[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	int	index = -1;
	for (int i=0; i<4; ++i)
	{
		if (input != arr[i])
			continue;
		index = i;
		break;
	}

	if (index == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}

	switch (index)
	{
		case 0: // debug
			std::cout << "[ DEBUG ]" << std::endl;
			h.complain("debug");
			std::cout << std::endl;
		case 1: // info
			std::cout << "[ INFO ]" << std::endl;
			h.complain("info");
			std::cout << std::endl;
		case 2: // warning
			std::cout << "[ WARNING ]" << std::endl;
			h.complain("warning");
			std::cout << std::endl;
		case 3: // error
			std::cout << "[ ERROR ]" << std::endl;
			h.complain("error");
			std::cout << std::endl;
	}

	return (0);
}
