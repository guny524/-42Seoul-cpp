#include <iostream>
#include <string>

#include "Bureaucrat.hpp"


int	main(void)
{
	try
	{
		Bureaucrat	b("b", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try
	{
		Bureaucrat	b("b", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try
	{
		Bureaucrat	b("b", 1);

		std::cout << b << std::endl;
		b.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	try
	{
		Bureaucrat	b("b", 150);

		std::cout << b << std::endl;
		b.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	return (0);
}
