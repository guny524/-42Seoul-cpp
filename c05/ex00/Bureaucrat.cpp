#include <iostream>
#include <string>

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void):
_name("default"),
_grade(_checkGrade(75))
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade):
_name(name),
_grade(_checkGrade(grade))
{}

Bureaucrat::Bureaucrat(const Bureaucrat& b):
_name(b._name),
_grade(_checkGrade(b._grade))
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this == &b)
		return (*this);
	*this = b;
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (_name);
}

const int&	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	++_grade;
}

int	Bureaucrat::_checkGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
