#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

void setColor(std::string col)
{
	std::cout << col;
}

int main()
{
	setColor(MAGENTA);
	const Animal* meta = new Animal();
	setColor(RED);
	const Animal* i = new Cat();
	setColor(BLUE);
	const Animal* j = new Dog();
	setColor(MAGENTA);
	const WrongAnimal* w = new WrongCat();
	setColor(RED);
	std::cout << i->getType() << " " << std::endl;
	setColor(BLUE);
	std::cout << j->getType() << " " << std::endl;

	setColor(RED);
	i->makeSound();

	setColor(BLUE);
	j->makeSound();

	setColor(MAGENTA);
	w->makeSound();
	meta->makeSound();
	setColor(MAGENTA);
	delete meta;
	setColor(RED);
	delete j;
	setColor(BLUE);
	delete i;
	setColor(MAGENTA);
	delete w;
	setColor(WHITE);
	return 0;
}