#include <iostream>
#include <string>

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm(void): AForm("rrf", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("rrf", 72, 45),
_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf): AForm(rrf),
_target(rrf._target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rrf)
{
	if (this == &rrf)
		return (*this);
	*this = rrf;
	return (*this);
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	checkExecute(b);
	if (rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& rrf)
{
	out << rrf.getName();
	out << ", RobotomyRequestForm gradeSgin " << rrf.getGradeSign();
	out << ", gradeExecute " << rrf.getGradeExecute();
	if (rrf.getIsSigned())
		out << ", is signed";
	else
		out << ", is not signed";
	out << ", target: " << rrf.getTarget();
	return (out);
}
