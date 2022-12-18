#include <iostream>
#include <exception>

#include "Span.hpp"


int main()
{
	Span	sp = Span(5);

	sp.addNumber(6);

	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	sp.print();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << std::endl;
	///////////////


	std::vector<int>	v;
	for (int i=0; i<6; ++i)
		v.push_back(i);

	try
	{
		sp.fill(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl;
	///////////////


	Span	sp2(15);

	sp2.fill(v.begin(), v.end());
	sp2.print();

	return (0);
}
