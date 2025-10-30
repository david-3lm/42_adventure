#include "../include/PmergeMe.hpp"


int main(int argc, char **argv)
{
	(void)argv;
	try
	{
		if (argc < 2)
		{
			throw std::runtime_error("Not enough arguments.");
			return 1;
		}
		PmergeMe pmerge_me(argv);
		std::cout << "Before: " << pmerge_me << std::endl;
		pmerge_me.sort();
		std::cout << "After: " << pmerge_me << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
