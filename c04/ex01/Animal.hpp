#pragma once
#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include <string>


class Animal
{
protected:
	std::string	_type;

public:
	Animal(void);
	Animal(const Animal& a);
	virtual ~Animal();

	virtual Animal&	operator=(const Animal& a);

	virtual std::string	getType(void) const;
	virtual void		makeSound(void) const;
};

#endif
