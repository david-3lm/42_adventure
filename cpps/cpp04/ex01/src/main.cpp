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
	Animal *list[100];
	setColor(BLUE);
	for (size_t i = 0; i < 50; i++)
	{
		list[i] = new Dog();
	}
	setColor(RED);
	for (size_t i = 50; i < 100; i++)
	{
		list[i] = new Cat();
	}
	setColor(BLUE);
	std::cout << "Idea de perro: " << ((Dog *)list[30])->getBrain()->getIdea(30) << std::endl;
	setColor(RED);
	std::cout << "Idea de gato: "<< ((Cat *)list[60])->getBrain()->getIdea(60) << std::endl;
	
	setColor(GREEN);
	for (size_t i = 0; i < 100; i++)
	{
		delete list[i];
	} 
	setColor(WHITE);
	return 0;
}