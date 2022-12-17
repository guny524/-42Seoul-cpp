#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(void):
_name("default"),
_isSigned(false),
_gradeSign(_checkGrade(75)),
_gradeExecute(_checkGrade(75))
{}

AForm::AForm(const std::string& name, const int& gradeSign, const int& gradeExecute):
_name(name),
_isSigned(false),
_gradeSign(gradeSign),
_gradeExecute(gradeExecute)
{
	_checkGrade(gradeSign);
	_checkGrade(gradeExecute);
}

AForm::AForm(const AForm& f):
_name(f._name),
_isSigned(f._isSigned),
_gradeSign(f._gradeSign),
_gradeExecute(f._gradeExecute)
{
	_checkGrade(f._gradeSign);
	_checkGrade(f._gradeExecute);
}

AForm::~AForm()
{}

AForm&	AForm::operator=(const AForm& f)
{
	if (this == &f)
		return (*this);
	*this = f;
	return (*this);
}

const std::string&	AForm::getName(void) const
{
	return (_name);
}

const bool&	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

const int&	AForm::getGradeSign(void) const
{
	return (_gradeSign);
}

const int&	AForm::getGradeExecute(void) const
{
	return (_gradeExecute);
}

const int&	AForm::_checkGrade(const int& grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

void	AForm::checkExecute(Bureaucrat const & b) const
{
	if (!(getIsSigned() && b.getGrade() <= getGradeExecute()))
		throw GradeTooLowException();
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& out, const AForm& f)
{
	out << f.getName();
	out << ", form gradeSign " << f.getGradeSign();
	out << ", gradeExecute " << f.getGradeExecute();
	if (f.getIsSigned())
		out << ", is signed";
	else
		out << ", is not signed";
	return (out);
}
