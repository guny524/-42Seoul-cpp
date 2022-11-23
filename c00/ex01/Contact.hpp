#pragma once
#ifndef __CONTACT_H__
# define __CONTACT_H__

# include <string>


class Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nick_name;
	std::string	_phone_number;
	std::string	_secret;

public:
	Contact(void);
	Contact(const Contact &ct);
	~Contact();

	Contact& operator=(const Contact &ct);

	void	setFirstName(const std::string first_name);
	void	setLastName(const std::string last_name);
	void	setNickName(const std::string nick_name);
	void	setPhoneNumber(const std::string phone_number);
	void	setSecret(const std::string secret);

	std::string	toStringDetail(const int width);
	std::string	toStringSimple(const int index, const int width);
};

#endif
