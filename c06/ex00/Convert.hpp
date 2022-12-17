#pragma once
#ifndef __CONVERT_H__
# define __CONVERT_H__

# include <iostream>
# include <string>


class Convert
{
private:
	enum {
		TYPE_ERROR = 0,
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE,
	};

	std::string	_raw;
	int			_type;

	char		_c;
	bool		_cNotAscii;
	int			_i;
	bool		_iOverFlowReal;
	bool		_iOverflow;
	float		_f;
	double		_d;
	bool		_nan;

	Convert(void);

public:
	Convert(const std::string& raw);
	Convert(const Convert& c);
	~Convert();

	Convert&	operator=(const Convert& c);

	int		detectType(std::string raw);
	bool	isChar(std::string raw);
	bool	isInt(std::string raw);
	bool	isFloat(std::string raw);
	bool	isDouble(std::string raw);

	void	convertRealType(std::string raw);
	void	convertOtherType();

	void	printAll(void);
	void	printChar(void);
	void	printInt(void);
	void	printFloat(void);
	void	printDouble(void);
};

#endif
