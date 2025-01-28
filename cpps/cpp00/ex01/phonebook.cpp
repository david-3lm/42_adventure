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
		c = aux;
	}
}

Contact Phonebook::GetContact(int i)
{
	return (contacts[i]);
}