#include <iostream>
#include <string>

#include "Convert.hpp"


Convert::Convert(void)
{}

Convert::Convert(const Convert& c)
{}

Convert::~Convert()
{}

Convert&	Convert::operator=(const Convert& c)
{
	if (this == &c)
		return (*this);
	*this = c;
	return (*this);
}

int		Convert::detectType(std::string raw)
{
	if (raw.empty())
		return (TYPE_ERROR);
	if (isChar(raw))
		return (TYPE_CHAR);
	int	type = IsInt(raw);

}

bool	Convert::isChar(std::string raw)
{

}

bool	Convert::isInt(std::string raw)
{

}

bool	Convert::isFloat(std::string raw)
{

}

bool	Convert::isDouble(std::string raw)
{

}

void	Convert::convertRealType(void)
{

}

void	Convert::convertOtherType(void)
{

}

void	Convert::printChar(void)
{

}

void	Convert::printInt(void)
{

}

void	Convert::printFloat(void)
{

}

void	Convert::printDouble(void)
{

}
