#include <iostream>
#include <string>
#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("scf", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("scf", 145, 137),
_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& scf): AForm(scf),
_target(scf._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& scf)
{
	if (this == &scf)
		return (*this);
	*this = scf;
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& b) const
{
	checkExecute(b);
	std::string tree =
"                     v .   ._, |_  .,\n"
"           `-._\\/  .  \\ /    |/_\n"
"               \\  _\\, y | \\//\n"
"         _\\_.___\\, \\/ -.\\||\n"
"           `7-,--.`._||  / / ,\n"
"           /'     `-. `./ / |/_.'\n"
"                     |    |//\n"
"                     |_    /\n"
"                     |-   |\n"
"                     |   =|\n"
"                     |    |\n"
"--------------------/ ,  . \\--------._\n";

	std::ofstream   outfile(_target + "_shrubbery");
	if (outfile.is_open())
	{
		outfile << tree;
		outfile.close();
	}
}

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& scf)
{
	out << scf.getName();
	out << ", ShrubberyCreationForm gradeSgin " << scf.getGradeSign();
	out << ", gradeExecute " << scf.getGradeExecute();
	if (scf.getIsSigned())
		out << ", is signed";
	else
		out << ", is not signed";
	out << ", target: " << scf.getTarget();
	return (out);
}

