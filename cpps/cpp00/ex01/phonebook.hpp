#pragma once
#include "contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
public:
	Phonebook();
	~Phonebook();
	void AddContact(Contact c);
	Contact GetContact(int i);
};
