#include "Phonebook.hpp"

Phonebook::Phonebook() { n_contacts = 0; }

Phonebook::~Phonebook() { }

void Phonebook::AddContact(Contact c)
{
	Contact aux;

	for (size_t i = 0; i < 8; i++)
	{
		aux = contacts[i];
		contacts[i] = c;
		c = aux;
	}
	if (n_contacts <= 8)
		n_contacts++;
}

Contact Phonebook::GetContact(int i)
{
	return (contacts[i]);
}