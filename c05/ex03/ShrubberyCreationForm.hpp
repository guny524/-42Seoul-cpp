#pragma once
#ifndef __SHRUBBERYCREATIONFORM_H__
# define __SHRUBBERYCREATIONFORM_H__

# include <iostream>
# include <string>

# include "AForm.hpp"


class ShrubberyCreationForm: public AForm
{
private:
	std::string	_target;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& scf);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& scf);

	const std::string&	getTarget(void) const;

	void	execute(const Bureaucrat& executor) const;
};

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& scf);

#endif
