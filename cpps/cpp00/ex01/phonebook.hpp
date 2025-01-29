#pragma once
#include "contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
public:
	int		n_contacts;
	Phonebook();
	~Phonebook();
	void AddContact(Contact c);
	Contact GetContact(int i);
};
