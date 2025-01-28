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
	std::cout << "Contacto añadido" << std::endl;
}

std::string TrimString(std::string str)
{
	size_t size = 10;
	std::string aux;

	if (str.size() > size)
	{
		aux = str.substr(0, size - 1);
		aux = aux.append(".");
	}
	else
	{
		aux = std::string(size - str.size(), ' ').append(str);
	}
	return (aux);
}

void Search(Phonebook *p)
{
	for (size_t i = 0; i < 8; i++)
	{
		if (p->GetContact(i).GetFirstName() != "")
		{
			std::cout << i << " | " << TrimString(p->GetContact(i).GetFirstName()) << " | " 
				<< TrimString(p->GetContact(i).GetLastName()) << " | " << TrimString(p->GetContact(i).GetNickName()) << std::endl;
		}
	}
	
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
			Search(phonebook);
		else if (input != "EXIT")
			std::cout << "Entrada no valida" << std::endl;
	}
	
	return 0;
}
