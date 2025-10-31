#include "../include/PmergeMe.hpp"

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
		{
			throw std::runtime_error("Not enough arguments.");
			return 1;
		}
		PmergeMe pmerge_me(argv);
		std::cout << "Before: " << pmerge_me <<std::endl;
		std::cout << BLUE;
		pmerge_me.sort();
		std::cout << WHITE;
		std::cout << "After: " << pmerge_me << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << WHITE << std::endl;
	}

	return 0;
}
