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

	int	_checkGrade(int grade);

	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what(void) const throw()
		{
			return ("Grade is too high !!!");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what(void) const throw()
		{
			return ("Grade is too low !!!");
		}
	};

public:
	Bureaucrat(void);
	Bureaucrat(const std::string& name, int grade);
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
