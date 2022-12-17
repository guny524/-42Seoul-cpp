#include <string>

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern(void)
{}

Intern::Intern(const Intern& i)
{
	*this = i;
}

Intern::~Intern()
{}

Intern&	Intern::operator=(const Intern& i)
{
	if (this == &i)
		return (*this);
	*this = i;
	return (*this);
}

AForm	*Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string formStrs[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm",
	};
	AForm	*forms[3] = {
		new PresidentialPardonForm(target),
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target),
	};

	AForm	*ret = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (name == formStrs[i])
			ret = forms[i];
		else
			delete forms[i];
	}
	if (ret == NULL)
		throw FormNotFound();
	std::cout << "Intern creates " << ret->getName() << std::endl;
	return (ret);
}

const char *Intern::FormNotFound::what(void) const throw()
{
	return ("Form not found");
}
