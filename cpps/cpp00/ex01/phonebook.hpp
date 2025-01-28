#include "contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
public:
	Phonebook();
	~Phonebook();
	AddContact(Contact c);
};

Phonebook::Phonebook()
{

}

Phonebook::~Phonebook()
{
}

void AddContact(Contact c)
{
	
}