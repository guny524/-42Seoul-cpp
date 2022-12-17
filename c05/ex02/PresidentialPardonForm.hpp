#pragma once
#ifndef __PRESIDENTIALPARDONFORM_H__
# define __PRESIDENTIALPARDONFORM_H__

# include <iostream>
# include <string>

# include "AForm.hpp"


class PresidentialPardonForm: public AForm
{
private:
	std::string	_target;

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& ppf);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& ppf);

	const std::string&	getTarget(void) const;

	void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& ppf);

#endif
