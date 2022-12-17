#pragma once
#ifndef __AFORM_H__
# define __AFORM_H__

# include <iostream>
# include <string>

class Bureaucrat;


class AForm
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
	AForm(void);
	AForm(const std::string& name, const int& gradesign, const int& gradeExecute);
	AForm(const AForm& f);
	~AForm();

	AForm&	operator=(const AForm& f);

	const std::string&	getName(void) const;
	const bool&			getIsSigned(void) const;
	const int&			getGradeSign(void) const;
	const int&			getGradeExecute(void) const;

	void	beSigned(const Bureaucrat& b);

	virtual void	execute(const Bureaucrat& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& out, const AForm& f);

#endif
