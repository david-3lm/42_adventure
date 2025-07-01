#include "Phonebook.hpp"
#include "Contact.hpp"
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
	while (first == "")
	{	
		std::cout << "Introduce first name => ";
		if (!std::getline(std::cin, first))
			return ;
	}

	while (last == "")
	{
		std::cout << "Introduce last name => ";
		if (!std::getline(std::cin, last))
			return ;
	}

	while (nick == "")
	{
		std::cout << "Introduce nickname => ";
		if (!std::getline(std::cin, nick))
			return ;
	}

	std::cout << "Introduce el número de telefono => ";
	if (!(std::cin >> number))
		return ;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "Necesito que introduzcas un numero" << std::endl;
		return ;
	}
	std::cin.ignore(10000, '\n');
	while (secret == "")
	{
		std::cout << "Introduce el secreto => ";
		if (!std::getline(std::cin, secret))
			return ;
	}
	c = new Contact(first, last, nick, number, secret);
	p->AddContact(*c);
	std::cout << "Contacto añadido" << std::endl;
	delete c;
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
	std::string idx;

	for (size_t i = 0; i < 8; i++)
	{
		if (p->GetContact(i).GetFirstName() != "")
		{
			std::cout << i << " | " << TrimString(p->GetContact(i).GetFirstName()) << " | " 
				<< TrimString(p->GetContact(i).GetLastName()) << " | " << TrimString(p->GetContact(i).GetNickName()) << std::endl;
		}
	}
	if (p->n_contacts == 0)
	{
		std::cout << "No hay contactos" << std::endl;
		return ;
	}
	while (true)
	{
		std::cout << "Introduce el índice del contacto a revisar => ";
		std::cin >> idx;
		std::cout << "INDX = " << atoi(idx.c_str()) << std::endl;
		if (std::cin.fail() || atoi(idx.c_str()) >= p->n_contacts || atoi(idx.c_str()) < 0)
		{
			std::cin.clear();
			std::cout << "		Índice inválido" << std::endl;
		}
		else
		{
			std::cout << p->GetContact(atoi(idx.c_str())).ToString();
			break;
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
		if (!(std::cin >> input))
		{
			std::cout << "SALIMOOOOOOOOOOOS" << std::endl;
			break ;
		}
		if (input == "ADD")
			Add(phonebook);
		else if (input == "SEARCH")
			Search(phonebook);
		else if (input != "EXIT")
			std::cout << "Entrada no valida" << std::endl;
	}
	delete phonebook;
	return 0;
}
