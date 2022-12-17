#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int	main(void)
{
	srand(time(NULL));

	Intern	intern;
	try
	{
		intern.makeForm("sdfsd", "target");
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	const Bureaucrat	*bureaucrats[3] = {
		new Bureaucrat("0", 140),
		new Bureaucrat("1", 50),
		new Bureaucrat("2", 5),
	};
	const AForm			*forms[3] = {
		intern.makeForm("PresidentialPardonForm", "scf"),
		intern.makeForm("RobotomyRequestForm", "rrf"),
		intern.makeForm("PresidentialPardonForm", "ppf"),
	};

	for (int i=0; i<3; ++i)
	{
		std::cout << *bureaucrats[i] << std::endl;
		std::cout << *forms[i] << std::endl;
	}
	std::cout << std::endl << std::endl;

	try
	{
		bureaucrats[0]->executeForm(*forms[0]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	bureaucrats[0]->signForm(*forms[0]);

	try
	{
		bureaucrats[0]->executeForm(*forms[0]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	bureaucrats[1]->signForm(*forms[0]);
	std::cout << *forms[0] << std::endl;
	std::cout << std::endl << std::endl;

	bureaucrats[1]->executeForm(*forms[0]);
	std::cout << std::endl << std::endl;

	for (int i=1; i<3; ++i)
	{
		bureaucrats[2]->signForm(*forms[i]);
		std::cout << *forms[i] << std::endl;
		bureaucrats[2]->executeForm(*forms[i]);
		std::cout << std::endl << std::endl;
	}

	for (int i=0; i<3; ++i)
		std::cout << *forms[i] << std::endl;

	for (int i=0; i<3; ++i)
	{
		delete bureaucrats[i];
		delete forms[i];
	}

	return (0);
}
