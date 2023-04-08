#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <string>
#include <map>


class BitcoinExchange
{
private:
	std::string						_data_file;
	std::string						_input_file;
	std::map<std::string, float>	_data;

	BitcoinExchange(void);

	void	check_date(const std::string& date);
	void	check_value(const float& value);
	float	get_price_before_date(const std::string& date);

	std::string	strip(const std::string& str);

public:
	BitcoinExchange(const std::string& input_file);
	BitcoinExchange(const BitcoinExchange& be);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	process();
};

#endif
