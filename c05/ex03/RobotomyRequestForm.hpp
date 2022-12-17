#pragma once
#ifndef __ROBOTOMYREQUESTFORM_H__
# define __ROBOTOMYREQUESTFORM_H__

# include <iostream>
# include <string>

# include "AForm.hpp"


class RobotomyRequestForm: public AForm
{
private:
	std::string	_target;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& rrf);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rrf);

	const std::string&	getTarget(void) const;

	void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& rrf);

#endif
