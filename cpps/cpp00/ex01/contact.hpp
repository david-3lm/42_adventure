#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
public:
	Contact(std::string fName, std::string lName, std::string nName);
	~Contact();
};

Contact::Contact(std::string fName, std::string lName, std::string nName)
{
	firstName = fName;
	lastName = lName;
	nickName = nName;
}

Contact::~Contact()
{
}
