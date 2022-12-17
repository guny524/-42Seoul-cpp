#include <iostream>
#include <string>

#include "Bureaucrat.hpp"


int	main(void)
{
	try
	{
		Bureaucrat	b1("b1", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
