#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* a = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	d->makeSound();
	c->makeSound();
	a->makeSound();

	delete a;
	delete d;
	delete c;


	std::cout << std::endl;
	//////////////


	// const WrongAnimal*	wa = new WrongAnimal();
	// const WrongAnimal*	wc= new WrongCat();

	// std::cout << wc->getType() << " " << std::endl;
	// wc->makeSound();
	// wa->makeSound();

	// delete wc;
	// delete wa;


	std::cout << std::endl;
	//////////////

	const int	num = 10;
	Animal	*arr[num];

	for (int i=0; i<num/2; ++i)
		arr[i] = new Dog();

	std::cout << std::endl;

	for (int i=num/2; i<num; ++i)
		arr[i] = new Cat();

	std::cout << std::endl;

	for (int i=0; i<num; ++i)
		arr[i]->makeSound();

	std::cout << std::endl;

	for (int i=0; i<num; ++i)
		delete arr[i];

	while (1);

	return (0);
}
