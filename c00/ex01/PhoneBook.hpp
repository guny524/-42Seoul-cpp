#pragma once
#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "Contact.hpp"


class	PhoneBook
{
private:
	Contact	_contacts[8];
	int		_cnt;
	int		_index;

	const int	WIDTH_DETAIL;
	const int	WIDTH_SIMPLE;

public:
	PhoneBook(void);
	PhoneBook(const PhoneBook &pb);
	~PhoneBook();

	PhoneBook& operator=(const PhoneBook &pb);

	int		len();
	void	addContact();
	void	searchContact();

	std::string	toString();
};

std::ostream& operator<<(std::ostream& out, PhoneBook &pb);

#endif
