#pragma once
#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <string>


class Bureaucrat
{
protected:
	const std::string	_name;
	int					_grade;

	const int&	_checkGrade(const int& grade) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

public:
	Bureaucrat(void);
	Bureaucrat(const std::string& name, const int& grade);
	Bureaucrat(const Bureaucrat& b);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& b);

	const std::string&	getName(void) const;
	const int&			getGrade(void) const;
	void				incrementGrade(void);
	void				decrementGrade(void);
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);

#endif
