#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>

void Add(Phonebook *p)
{
	std::string first;
	std::string last;
	std::string nick;
	int			number;
	std::string secret;
	Contact 	*c;

	std::cin.ignore(10000, '\n');
	std::cout << "Introduce first name => ";
	std::getline(std::cin, first);
	std::cout << "Introduce last name => ";
	std::getline(std::cin, last);
	std::cout << "Introduce nickname => ";
	std::getline(std::cin, nick);
	std::cout << "Introduce el número de telefono => ";
	std::cin >> number;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "Necesito que introduzcas un numero" << std::endl;
		return ;
	}
	std::cin.ignore(10000, '\n');
	std::cout << "Introduce el secreto => ";
	std::getline(std::cin, secret);
	c = new Contact(first, last, nick, number, secret);
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
	int idx;

	for (size_t i = 0; i < 8; i++)
	{
		if (p->GetContact(i).GetFirstName() != "")
		{
			std::cout << i << " | " << TrimString(p->GetContact(i).GetFirstName()) << " | " 
				<< TrimString(p->GetContact(i).GetLastName()) << " | " << TrimString(p->GetContact(i).GetNickName()) << std::endl;
		}
	}
	std::cout << "Introduce el índice del contacto a revisar => ";
	std::cin >> idx;
	if (std::cin.fail() || idx >= p->n_contacts)
	{
		std::cin.clear();
		Search(p);
	}
	else
	{
		std::cout << p->GetContact(idx).ToString();
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
