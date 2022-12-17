#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat(void):
_name("default"),
_grade(_checkGrade(75))
{}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade):
_name(name),
_grade(grade)
{
	_checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& b):
_name(b._name),
_grade(b._grade)
{
	_checkGrade(b._grade);
}

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

const int&	Bureaucrat::_checkGrade(const int& grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

void	Bureaucrat::signForm(const AForm& f) const
{
	try
	{
		const_cast<AForm&>(f).beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " execute " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
