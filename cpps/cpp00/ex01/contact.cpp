#include "contact.hpp"

Contact::Contact(std::string fName, std::string lName, std::string nName) : firstName(fName), lastName(lName), nickName(nName) {}

Contact::Contact() : firstName(""), lastName(""), nickName("") {}

Contact::~Contact() {}
