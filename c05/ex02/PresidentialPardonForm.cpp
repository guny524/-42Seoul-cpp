#include <iostream>
#include <string>

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(void): AForm("ppf", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("ppf", 25, 5),
_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ppf): AForm(ppf),
_target(ppf._target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ppf)
{
	if (this == &ppf)
		return (*this);
	*this = ppf;
	return (*this);
}

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	checkExecute(b);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& ppf)
{
	out << ppf.getName();
	out << ", PresidentialPardonForm gradeSgin " << ppf.getGradeSign();
	out << ", gradeExecute " << ppf.getGradeExecute();
	if (ppf.getIsSigned())
		out << ", is signed";
	else
		out << ", is not signed";
	out << ", target: " << ppf.getTarget();
	return (out);
}
