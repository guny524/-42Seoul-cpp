#include <iostream>
#include <sstream>
#include <limits>

#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void):
_cnt(0),
_index(0),
WIDTH_DETAIL(15),
WIDTH_SIMPLE(10)
{}

PhoneBook::PhoneBook(const PhoneBook &pb):
_cnt(pb._cnt),
_index(pb._index),
WIDTH_DETAIL(15),
WIDTH_SIMPLE(10)
{
	for (int i=0; i<pb._cnt; ++i)
		_contacts[i] = pb._contacts[i];
}

PhoneBook::~PhoneBook()
{}

PhoneBook& PhoneBook::operator=(const PhoneBook &pb)
{
	_cnt = pb._cnt;
	_index = pb._index;
	for (int i=0; i<pb._cnt; ++i)
		_contacts[i] = pb._contacts[i];
	return (*this);
}

int	PhoneBook::len()
{
	return (_cnt);
}

void	PhoneBook::addContact()
{
	std::string	input;
	Contact	contact;

	// get input

	std::cout << "Please type First Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	else if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max());
		std::cout << "input fail" << std::endl;
		return ;
	}
	contact.setFirstName(input);

	std::cout << "Please type Last Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	else if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max());
		std::cout << "input fail" << std::endl;
		return ;
	}
	contact.setLastName(input);

	std::cout << "Please type Nick Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	else if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max());
		std::cout << "input fail" << std::endl;
		return ;
	}
	contact.setNickName(input);

	std::cout << "Please type Phone Number: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	else if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max());
		std::cout << "input fail" << std::endl;
		return ;
	}
	contact.setPhoneNumber(input);

	std::cout << "Please type secret: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	else if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max());
		std::cout << "input fail" << std::endl;
		return ;
	}
	contact.setSecret(input);

	// add to array

	if (_cnt != 8)
		++_cnt;
	_contacts[_index] = contact;
	_index = ++_index % 8;
}

void	PhoneBook::searchContact()
{
	std::string	input;

	std::cout << *this << std::endl;

	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	else if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<int>::max());
		std::cout << "input fail" << std::endl;
		return ;
	}
	std::stringstream	st(input);
	int					i;

	st >> i;
	if (i <= 0)
		std::cout << "input is something wrong not integer index" << std::endl;
	else if (i > _cnt)
		std::cout << "out of range" << std::endl;
	else
		std::cout << _contacts[i - 1].toStringDetail(this->WIDTH_DETAIL) << std::endl;
}

std::string	PhoneBook::toString()
{
	std::stringstream	st;
	Contact				emptyContact;

	st << emptyContact.toStringSimple(-1, this->WIDTH_SIMPLE) << std::endl;
	for (int i=0; i<_cnt; ++i)
		st << _contacts[i].toStringSimple(i + 1, this->WIDTH_SIMPLE) << std::endl;

	return (st.str());
}

std::ostream& operator<<(std::ostream& out, PhoneBook &pb)
{
	out << pb.toString() << std::endl;
	return (out);
}
