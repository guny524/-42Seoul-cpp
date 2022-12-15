#pragma once
#ifndef __CAT_H__
# define __CAT_H__

# include <string>

# include "Animal.hpp"


class Cat: public Animal
{
public:
	Cat(void);
	Cat(const Cat& a);
	virtual ~Cat();

	Cat&	operator=(const Cat& a);

	std::string	getType(void) const;
	void		makeSound(void) const;

};

#endif
