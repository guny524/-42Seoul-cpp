#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{}

Base	*generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (new A);
		break;
		case 1:
			return (new B);
		break;
		case 2:
			return (new C);
		break;
	}
	return static_cast<Base*>(NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Nothing" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (const std::exception& e) {
		;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (const std::exception& e) {
		;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (const std::exception& e) {
		;
	}
}
