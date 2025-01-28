#include "phonebook.hpp"

Phonebook::Phonebook() {}

Phonebook::~Phonebook() {}

void Phonebook::AddContact(Contact c)
{
	Contact aux;

	for (size_t i = 0; i < 8; i++)
	{
		aux = contacts[i];
		contacts[i] = c;
		aux = c;
	}
}