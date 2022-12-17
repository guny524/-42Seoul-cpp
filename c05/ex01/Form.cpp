#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(void):
_name("default"),
_isSigned(false),
_gradeSign(_checkGrade(75)),
_gradeExecute(_checkGrade(75))
{}

Form::Form(const std::string& name, const int& gradeSign, const int& gradeExecute):
_name(name),
_isSigned(false),
_gradeSign(gradeSign),
_gradeExecute(gradeExecute)
{
	_checkGrade(gradeSign);
	_checkGrade(gradeExecute);
}

Form::Form(const Form& f):
_name(f._name),
_isSigned(f._isSigned),
_gradeSign(f._gradeSign),
_gradeExecute(f._gradeExecute)
{
	_checkGrade(f._gradeSign);
	_checkGrade(f._gradeExecute);
}

Form::~Form()
{}

Form&	Form::operator=(const Form& f)
{
	if (this == &f)
		return (*this);
	*this = f;
	return (*this);
}

const std::string&	Form::getName(void) const
{
	return (_name);
}

const bool&	Form::getIsSigned(void) const
{
	return (_isSigned);
}

const int&	Form::getGradeSign(void) const
{
	return (_gradeSign);
}

const int&	Form::getGradeExecute(void) const
{
	return (_gradeExecute);
}

const int&	Form::_checkGrade(const int& grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& out, const Form& f)
{
	out << f.getName() << ", ";
	out << "form gradeSgin " << f.getGradeSign() << ", ";
	out << "gradeExecute " << f.getGradeExecute() << ", ";
	if (f.getIsSigned())
		out << "is signed";
	else
		out << "is not signed";
	out << std::endl;
	return (out);
}
