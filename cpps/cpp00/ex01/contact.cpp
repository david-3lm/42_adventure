#include "contact.hpp"

Contact::Contact(std::string fName, std::string lName, std::string nName, int number, std::string sec) 
	: firstName(fName), lastName(lName), nickName(nName), number(number), secret(sec) {}

Contact::Contact() : firstName(""), lastName(""), nickName("") {}

Contact::~Contact() {}

std::string Contact::ToString()
{
	std::string str;
	std::stringstream ss;

	str = firstName.append("\n");
	str = str.append(lastName);
	str = str.append("\n");
	str = str.append(nickName);
	str = str.append("\n");
	ss << number;
	str = str.append(ss.str());
	str = str.append("\n");
	str = str.append(secret);
	str = str.append("\n");
	return (str);
}
