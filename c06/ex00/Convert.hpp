#pragma once
#ifndef __CONVERT_H__
# define __CONVERT_H__

# include <iostream>
# include <string>


class Convert
{
protected:
	enum {
		TYPE_ERROR = 0,
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DPUBLE,
	};

	std::string	raw;


public:
	Convert(void);
	Convert(const Convert& c);
	~Convert();

	Convert&	operator=(const Convert& c);

	int		detectType(std::string raw);
	bool	isChar(std::string raw);
	bool	isInt(std::string raw);
	bool	isFloat(std::string raw);
	bool	isDouble(std::string raw);

	void	convertRealType(void);
	void	convertOtherType(void);

	void	printChar(void);
	void	printInt(void);
	void	printFloat(void);
	void	printDouble(void);
};

#endif
