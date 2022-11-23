#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

#include "PhoneBook.hpp"


std::string	to_upper(std::string &str)
{
	std::string	ret(str);

	for (std::string::iterator iter=ret.begin(); iter!=ret.end(); ++iter)
		*iter = static_cast<char>(toupper(*iter));
	return (ret);
}

int	main(void)
{
	std::string	input;
	PhoneBook pb = PhoneBook();

	while (true)
	{
		std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
		std::cout << "Enter Command" << std::endl;
		std::cout << "ADD" << std::endl;
		std::cout << "SEARCH" << std::endl;
		std::cout << "EXIT" << std::endl;
		std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;

		// get word
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		else if (std::cin.fail()) // 위에 eof 체크 안 하면 ctrl-D 눌렀을 때 무한 반복
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max());
			std::cout << "input fail" << std::endl;
			continue;
		}

		// to upper
		input = to_upper(input);

		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.searchContact();
		else if (input == "EXIT")
			break;

		if (std::cin.eof())
			return (0);
	}
	return (0);
}
