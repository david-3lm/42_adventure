#include <iostream>


int main( void )
{
	std::string s = "HI THIS IS BRAIN";
	std::string* sPTR = &s;
	std::string& sREF = s;

	std::cout << "ADDRESS OF VARIABLE => " << &s << std::endl;
	std::cout << "ADDRESS OF POINTER => " << sPTR << std::endl;
	std::cout << "ADDRESS OF REFERENCE => " << &sREF << std::endl;
	
	
	std::cout << "VALUE OF VARIABLE => " << s << std::endl;
	std::cout << "VALUE OF POINTER => " << *sPTR << std::endl;
	std::cout << "VALUE OF REFERENCE => " << sREF << std::endl;
	return 0;
}
