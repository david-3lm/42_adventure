#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *list[100];
	for (size_t i = 0; i < 50; i++)
	{
		list[i] = new Dog();
	}
	for (size_t i = 50; i < 100; i++)
	{
		list[i] = new Cat();
	}
	
	std::cout << ((Dog *)list[30])->getBrain()->getIdea(30) << std::endl;

	for (size_t i = 0; i < 100; i++)
	{
		delete list[i];
	}
	return 0;
}