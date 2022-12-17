#pragma once
#ifndef __FORM_H__
# define __FORM_H__

# include <iostream>
# include <string>

class Bureaucrat;


class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExecute;

protected:
	const int&	_checkGrade(const int& grade) const;

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
	Form(void);
	Form(const std::string& name, const int& gradesign, const int& gradeExecute);
	Form(const Form& f);
	~Form();

	Form&	operator=(const Form& f);

	const std::string&	getName(void) const;
	const bool&			getIsSigned(void) const;
	const int&			getGradeSign(void) const;
	const int&			getGradeExecute(void) const;

	void	beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& out, const Form& f);

#endif
