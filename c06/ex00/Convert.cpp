#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>

#include "Convert.hpp"


Convert::Convert(void) // private
{}

Convert::Convert(const std::string& raw):
_raw(raw),
_type(TYPE_ERROR),
_cNotAscii(false),
_iOverFlowReal(false),
_iOverflow(false),
_nan(false)
{
	_type = detectType(raw);
	convertRealType(raw);
	convertOtherType();
}

Convert::Convert(const Convert& c)
{
	*this = c;
}

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
	else if (isChar(raw))
		return (TYPE_CHAR);
	else if (isInt(raw))
		return (TYPE_INT);
	else if (isFloat(raw))
		return (TYPE_FLOAT);
	else if (isDouble(raw))
		return (TYPE_DOUBLE);
	return (TYPE_ERROR);
}

bool	Convert::isChar(std::string raw)
{
	// '0' 'a'
	if (raw.length() == 3 && raw[0] == '\'' && raw[2] == '\'')
		return (true);
	// a
	else if (raw.length() == 1 && !isdigit(raw[0]))
		return (true);
	// 5
	return (false);
}

bool	Convert::isInt(std::string raw)
{
	char	*end = NULL;

	// "123.456f"
	// end = ".456f"
	std::strtol(raw.c_str(), &end, 10);
	if (end == NULL)
		return (true);
	return (false);
}

bool	Convert::isFloat(std::string raw)
{
	char	*end = NULL;

	// "123.456f"
	// end = "f"
	std::strtod(raw.c_str(), &end);
	if (strlen(end) == 1 && *end == 'f')
		return (true);
	return (false);
}

bool	Convert::isDouble(std::string raw)
{
	char	*end = NULL;

	std::strtod(raw.c_str(), &end);
	if (*end == '\0')
		return (true);
	return (false);
}

void	Convert::convertRealType(std::string raw)
{
	long	l;

	switch (_type)
	{
		case TYPE_CHAR:
			if (_raw.length() == 1) // a
				_c = raw[0];
			else // 'a'
				_c = raw[1];
			break;
		case TYPE_INT:
			l = strtol(raw.c_str(), NULL, 10);
			if (!(std::numeric_limits<int>::min() <= l && l <= std::numeric_limits<int>::max()))
				_iOverFlowReal = true;
			_i = static_cast<int>(l);
			break;
		case TYPE_FLOAT:
			// "nan"
			if (raw == "nan" || raw == "+nan" || raw == "-nan")
				_nan = true;
			_f = static_cast<float>(strtod(raw.c_str(), NULL));
			break;
		case TYPE_DOUBLE:
			// "nan"
			if (raw == "nan" || raw == "+nan" || raw == "-nan")
				_nan = true;
			_d = strtod(raw.c_str(), NULL);
			break;
	}
}

void	Convert::convertOtherType()
{
	long	l;

	switch (_type)
	{
		case TYPE_CHAR:
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			break;
		case TYPE_INT:
			if (!isascii(_i))
				_cNotAscii = true;
			else
				_c = static_cast<char>(_i);
			_f = static_cast<float>(_i);
			_d = static_cast<double>(_i);
			break;
		case TYPE_FLOAT:
			if (!isascii(static_cast<int>(_f)))
				_cNotAscii = true;
			else
				_c = static_cast<char>(_f);
			l = static_cast<long>(_f);
			if (!(std::numeric_limits<int>::min() <= l && l <= std::numeric_limits<int>::max()))
				_iOverflow = true;
			_i = static_cast<int>(_f);
			_d = static_cast<double>(_f);
			break;
		case TYPE_DOUBLE:
			if (!isascii(static_cast<int>(_d)))
				_cNotAscii = true;
			else
				_c = static_cast<char>(_d);
			l = static_cast<long>(_d);
			if (!(std::numeric_limits<int>::min() <= l && l <= std::numeric_limits<int>::max()))
				_iOverflow = true;
			_i = static_cast<int>(_d);
			_f = static_cast<float>(_d);
			break;
	}
}

void	Convert::printAll(void)
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void	Convert::printChar(void)
{
	std::cout << "char: ";
	if (_type == TYPE_ERROR || _iOverFlowReal || _cNotAscii || _nan)
		std::cout << "impossible";
	else if (!isprint(_c))
		std::cout << "Non displayable";
	else
		std::cout << '\'' << _c << '\'';
	std::cout << std::endl;
}

void	Convert::printInt(void)
{
	std::cout << "int: ";
	if (_type == TYPE_ERROR || _iOverFlowReal || _iOverflow || _nan)
		std::cout << "impossible";
	else
		std::cout << _i;
	std::cout << std::endl;
}

void	Convert::printFloat(void)
{
	std::cout << "float: ";
	if (_type == TYPE_ERROR || _iOverFlowReal)
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << _f << "f";
	std::cout << std::endl;
}

void	Convert::printDouble(void)
{
	std::cout << "double: ";
	if (_type == TYPE_ERROR || _iOverFlowReal)
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << _d;
	std::cout << std::endl;
}
