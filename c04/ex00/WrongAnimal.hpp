#pragma once
#ifndef __WRONGANIMAL_H__
# define __WRONGANIMAL_H__

# include <string>


class WrongAnimal
{
protected:
	std::string	_type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& a);
	~WrongAnimal();

	WrongAnimal&	operator=(const WrongAnimal& a);

	std::string	getType(void) const;
	void		makeSound(void) const;
};

#endif
