#pragma once
#ifndef __INTERN_H__
# define __INTERN_H__

# include <string>

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"


class	Intern
{
private:
	class FormNotFound : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

public:
	Intern(void);
	Intern(const Intern& i);
	~Intern();

	Intern&	operator=(const Intern& i);

	AForm	*makeForm(const std::string& name, const std::string& target);
};

#endif
