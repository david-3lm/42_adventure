#pragma once
#include <string>
#include <sstream>
#include <stdlib.h>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string	number;
	std::string	secret;
public:
	Contact(std::string fName, std::string lName, std::string nName, std::string number, std::string sec);
	Contact();
	~Contact();
	std::string GetFirstName() { return (firstName); }
	std::string GetLastName() { return (lastName); }
	std::string GetNickName() { return (nickName); }
	std::string	GetNumber() { return (number); }
	std::string GetSecret() { return (secret); }
	std::string ToString();
};

