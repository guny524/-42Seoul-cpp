#pragma once
#ifndef __AMATERIA_H__
# define __AMATERIA_H__

# include <string>

class ICharacter;


class	AMateria
{
protected:
	const std::string	_type;

public:
	AMateria(void);
	AMateria(const std::string& type);
	AMateria(const AMateria& am);
	virtual	~AMateria();

	AMateria&	operator=(const AMateria& am);

	const std::string&	getType() const;

	virtual	AMateria*	clone() const = 0;
	virtual	void		use(ICharacter& target);
};

#endif
