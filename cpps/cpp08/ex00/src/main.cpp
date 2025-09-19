#include "easyfind.hpp"
#include <list>
#include <iostream>

int	main() 
{
	std::list<int>	lst;
	int				ret;

	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(32);
	lst.push_back(15);

	try {
		ret = easyfind(lst, 33);
		std::cout << "Value found : " << ret << "." << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	

	return 0;
}
