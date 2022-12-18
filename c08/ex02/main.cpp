#include <iostream>
#include <vector>

#include "MutantStack.hpp"


int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	std::cout << std::endl;
	/////


	MutantStack<int>	ms;
	std::vector<int>	v;

	for (int i=0; i<10; ++i)
	{
		ms.push(i);
		v.push_back(i);
	}

	for (MutantStack<int>::iterator	iter=ms.begin(); iter!=ms.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
	for (std::vector<int>::iterator	iter=v.begin(); iter!=v.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << ms.top() << std::endl;
	ms.pop();
	ms.pop();
	ms.push(100);

	for (MutantStack<int>::iterator	iter=ms.begin(); iter!=ms.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;

	return (0);
}
