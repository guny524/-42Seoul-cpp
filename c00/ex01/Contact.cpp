#include <iostream>
#include <iomanip>
#include <sstream>

#include "Contact.hpp"


Contact::Contact(void):
_first_name("First Name"),
_last_name("Last Name"),
_nick_name("Nick Name"),
_phone_number("010-1234-5678"),
_secret("no secret")
{}

Contact::Contact(const Contact &ct):
_first_name(ct._first_name),
_last_name(ct._last_name),
_nick_name(ct._nick_name),
_phone_number(ct._phone_number),
_secret(ct._secret)
{}

Contact::~Contact() {}

Contact& Contact::operator=(const Contact &ct)
{
	_first_name = ct._first_name;
	_last_name = ct._last_name;
	_nick_name = ct._nick_name;
	_phone_number = ct._phone_number;
	_secret = ct._secret;
	return (*this);
}

void	Contact::setFirstName(const std::string first_name)
{
	_first_name = first_name;
}

void	Contact::setLastName(const std::string last_name)
{
	_last_name = last_name;
}

void	Contact::setNickName(const std::string nick_name)
{
	_nick_name = nick_name;
}

void	Contact::setPhoneNumber(const std::string phone_number)
{
	_phone_number = phone_number;
}

void	Contact::setSecret(const std::string secret)
{
	_secret = secret;
}

std::string	Contact::toStringDetail(const int width)
{
	std::stringstream	st;

	st << "Print Detail!!" << std::endl;

	st << std::setiosflags(std::ios::left);

	st << std::setw(width) << "Fist Name: ";
	st << _first_name << std::endl;

	st << std::setw(width) << "Last Name: ";
	st << _last_name << std::endl;

	st << std::setw(width) << "Nick Name: ";
	st << _nick_name << std::endl;

	st << std::setw(width) << "Phone Number: ";
	st << _phone_number << std::endl;

	st << std::setw(width) << "Secret: ";
	st << _secret << std::endl;

	return (st.str());
}

std::string	Contact::toStringSimple(const int index, const int width)
{
	std::stringstream	st;

	st << std::setiosflags(std::ios::right);

	if (index < 0)
		st << std::setw(width) << "Index";
	else
		st << std::setw(width) << std::to_string(index).substr(0, 9);
	st << "|";

	if (_first_name.size() <= width)
		st << std::setw(width) << _first_name;
	else
		st << _first_name.substr(0, 9) << ".";
	st << "|";

	if (_last_name.size() <= width)
		st << std::setw(width) << _last_name;
	else
		st << _last_name.substr(0, 9) << ".";
	st << "|";

	if (_nick_name.size() <= width)
		st << std::setw(width) << _nick_name;
	else
		st << _nick_name.substr(0, 9) << ".";

	return (st.str());
}
