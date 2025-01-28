#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>

void Add(Phonebook *p)
{
	std::string first;
	std::string last;
	std::string nick;
	Contact *c;

	std::cout << "Introduce first name => ";
	std::cin >> first; 
	std::cout << "Introduce last name => ";
	std::cin >> last; 
	std::cout << "Introduce nickname => ";
	std::cin >> nick;
	c = new Contact(first, last, nick);
	p->AddContact(*c);
	std::cout << "Contacto añadido";
}

int main(void)
{
	std::string input;
	Phonebook *phonebook = new Phonebook();
	
	while (input != "EXIT")
	{
		std::cout << "¿QUÉ QUIERES HACER? (ADD, SEARCH, EXIT) => ";
		std::cin >> input; 
		if (input == "ADD")
			Add(phonebook);
		else if (input == "SEARCH")
			std::cout << "Elegiste add" << std::endl;
		else if (input != "EXIT")
			std::cout << "Entrada no valida" << std::endl;
	}
	
	return 0;
}
