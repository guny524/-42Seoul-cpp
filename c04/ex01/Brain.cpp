#include <iostream>
#include <string>
#include <sstream>

#include "Brain.hpp"


Brain::Brain(void)
{
	std::cout << "Brain Default Constructor" << std::endl;

	std::stringstream	st;

	for (int i=0; i<_NUM; ++i)
	{
		st << i;
		_ideas[i] = st.str();
		st.str(""); // flush
	}
}

Brain::Brain(const Brain& b)
{
	std::cout << "Brain Copy Constructor" << std::endl;

	for (int i=0; i<_NUM; ++i)
		_ideas[i] = b._ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& b)
{
	std::cout << "Brain Copy Operator" << std::endl;

	for (int i=0; i<_NUM; ++i)
		_ideas[i] = b._ideas[i];

	return (*this);
}

void		Brain::setIdea(int idx, std::string idea)
{
	_ideas[idx] = idea;
}

std::string	Brain::getIdea(int idx) const
{
	return (_ideas[idx]);
}
