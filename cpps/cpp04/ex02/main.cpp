#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	AAnimal *c = new Cat();
	// AAnimal *c = new AAnimal(); // ERROR PORQUE ES ABSTRACTA

	c->makeSound();

	delete c;
}