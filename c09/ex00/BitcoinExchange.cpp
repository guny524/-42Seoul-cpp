#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>


BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const std::string &input_file):
_data_file("data.csv"),
_input_file(input_file)
{
	std::ifstream data(_data_file.c_str());
	if (!data.is_open())
		throw std::runtime_error("could not open data file" + _data_file);

	// remove header
	std::string header;
	std::getline(data, header);

	std::string line;
	while (!(data.fail() || data.eof()))
	{
		// line
		std::getline(data, line);
		if (data.eof())
			break;
		if (data.fail())
			throw std::runtime_error("fail to read line in data file " + _data_file);
		std::istringstream linestream(line.c_str());

		// format check date
		std::string date;
		std::getline(linestream, date, ',');
		if (linestream.fail() || linestream.eof())
			throw std::runtime_error("bad data => " + line);
		date = strip(date);

		// format check price
		std::string price_str;
		std::getline(linestream, price_str);
		if (linestream.fail() || !linestream.eof())
			throw std::runtime_error("bad data => " + line);
		price_str = strip(price_str);

		std::istringstream price_stream(price_str.c_str());
		float price;
		price_stream >> price;
		if (price_stream.fail () || !price_stream.eof())
			throw std::runtime_error("bad data =>" + line);

		// check
		check_date(date);
		if (price < 0)
			throw std::runtime_error("bad data =>" + line);

		_data[date] = price;

	}
	if (!data.eof() && data.fail())
		throw std::runtime_error("fail to read line data file " + _data_file);

	data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& be):
_data_file(be._data_file),
_input_file(be._input_file),
_data(be._data)
{}

BitcoinExchange::~BitcoinExchange()
{
	_data.clear();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);
	this->_data_file = other._data_file;
	this->_input_file = other._input_file;
	this->_data = other._data;
	return (*this);
};

void	BitcoinExchange::check_date(const std::string& date)
{
	// struct tm t;
	// strptime(date.c_str(), "%Y-%m-%d", &t);

	if (std::count(date.begin(), date.end(), '-') != 2)
		throw std::runtime_error("bad date => " + date);

	std::istringstream stream(date.c_str());

	// year
	std::string year_str;
	std::getline(stream, year_str, '-');
	if (stream.fail() || stream.eof())
		throw std::runtime_error("bad date year => " + date);

	std::istringstream year_stream(year_str.c_str());
	int year;
	year_stream >> year;
	if (year_stream.fail() || !year_stream.eof())
		throw std::runtime_error("bad date year => " + date);

	// month
	std::string month_str;
	std::getline(stream, month_str, '-');
	if (stream.fail() || stream.eof())
		throw std::runtime_error("bad date month => " + date);

	std::istringstream month_stream(month_str.c_str());
	int month;
	month_stream >> month;
	if (month_stream.fail() || !month_stream.eof())
		throw std::runtime_error("bad date month => " + date);

	if (!(1 <= month && month <= 12))
		throw std::runtime_error("bad date month => " + date);

	// day
	std::string day_str;
	std::getline(stream, day_str, '-');
	if (stream.fail() || !stream.eof())
		throw std::runtime_error("bad date day => " + date);

	std::istringstream day_stream(day_str.c_str());
	int day;
	day_stream >> day;
	if (day_stream.fail() || !day_stream.eof())
		throw std::runtime_error("bad date day => " + date);

	if (month == 2)
	{
		// leap year check
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (!(1 <= day && day <= 29))
				throw std::runtime_error("bad date day => " + date);
		}
		else
		{
			if (!(1 <= day && day <= 28))
				throw std::runtime_error("bad date day => " + date);
		}
	}
	else
	{
		if ((month <= 7 && !(month % 2)) || (month > 7 && month % 2))
		{
			if (!(1 <= day && day <= 30))
				throw std::runtime_error("bad date day => " + date);
		}
		else
		{
			if (!(1 <= day && day <= 31))
				throw std::runtime_error("bad date day => " + date);
		}
	}
}

void	BitcoinExchange::check_value(const float& value)
{
	if (value <= 0.0f)
		throw std::runtime_error("not a positive number.");
	if (1000 <= value)
		throw std::runtime_error("too large a number.");
}

float	BitcoinExchange::get_price_before_date(const std::string &date)
{
	std::map<std::string, float>::const_iterator iter = _data.lower_bound(date);

	if (date != iter->first)
		--iter;
	if (iter == _data.begin())
		throw std::runtime_error("could not find price before then date " + date);
	return iter->second;
}

std::string	BitcoinExchange::strip(const std::string &str)
{
	std::string::const_iterator			begin = str.begin();
	std::string::const_reverse_iterator	end = str.rbegin();

	while (std::isspace(*begin))
		++begin;
	while (std::isspace(*end))
		++end;

	return std::string(begin, end.base());
}

void	BitcoinExchange::process()
{
	std::ifstream input(_input_file.c_str());
	if (!input.is_open())
		throw std::runtime_error("could not open input file " + _input_file);

	// remove header
	std::string header;
	std::getline(input, header);

	std::string line;
	while (!(input.fail() || input.eof()))
	{
		try {
			// line
			std::getline(input, line);
			if (input.eof())
				break;
			if (input.fail())
				throw std::runtime_error("fail to read line in input file " + _input_file);
			std::istringstream linestream(line.c_str());

			// format check date
			std::string date;
			std::getline(linestream, date, '|');
			if (linestream.fail() || linestream.eof())
				throw std::runtime_error("bad input => " + line);
			date = strip(date);

			// format check value
			std::string value_str;
			std::getline(linestream, value_str);
			if (linestream.fail() || !linestream.eof())
				throw std::runtime_error("bad input => " + line);
			value_str = strip(value_str);

			std::istringstream value_stream(value_str.c_str());
			float value;
			value_stream >> value;
			if (value_stream.fail() || !value_stream.eof())
				throw std::runtime_error("bad input => " + line);

			// check
			check_date(date);
			check_value(value);

			// print
			float price = get_price_before_date(date);
			std::cout << date << " => " << value << " = " << price * value << std::endl;

		} catch(std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	if (!input.eof() && input.fail())
		throw std::runtime_error("fail to read line input file " + _input_file);

	input.close();
}
