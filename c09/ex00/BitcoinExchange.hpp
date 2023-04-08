#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <string>
#include <map>
#include <exception>


class BitcoinExchange
{
private:
	std::string						_data_file;
	std::string						_input_file;
	std::map<std::string, double>	_data;

	BitcoinExchange(void);

	void	check_date(const std::string& date);
	void	check_value(const double& value);
	double	get_price_before_date(const std::string& date);

	std::string	strip(const std::string& str);

	class StringException : public std::exception
	{
	private:
		std::string _message;

		StringException(void);

		StringException&	operator=(const StringException& se);
	public:
		StringException(const std::string& message);
		StringException(const StringException& se);
		~StringException() throw();

		const char *what(void) const throw();
	};

public:
	BitcoinExchange(const std::string& input_file);
	BitcoinExchange(const BitcoinExchange& be);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	process();
};

#endif
