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


	const WrongAnimal*	wa = new WrongAnimal();
	const WrongAnimal*	wc= new WrongCat();

	std::cout << wc->getType() << " " << std::endl;
	wc->makeSound();
	wa->makeSound();

	delete wc;
	delete wa;


	std::cout << std::endl;
	//////////////


	Cat		c2;
	Animal	a2(c2);

	c2.makeSound();
	a2.makeSound();

	// Animal	a3;
	// Cat		c3(a3);

	// a3.makeSound();
	// c3.makeSound();

	return (0);
}
