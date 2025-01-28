#pragma once
#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
public:
	Contact(std::string fName, std::string lName, std::string nName);
	Contact();
	~Contact();
};

