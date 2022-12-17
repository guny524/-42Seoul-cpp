#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main(void)
{
	try
	{
		Form	f("f", 0, 75);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try
	{
		Form	f("f", 151, 75);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	Form		f("f", 2, 75);
	Bureaucrat	b("b", 3);

	std::cout << f << std::endl;
	std::cout << b << std::endl;

	b.signForm(f);
	std::cout << f << std::endl;

	b.incrementGrade();
	std::cout << b << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;

	return (0);
}
