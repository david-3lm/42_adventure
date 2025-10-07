#include "PmergeMe.hpp"


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
		PmergeMe<std::deque<int> > deque(argv);
		PmergeMe<std::vector<int> > vector(argv);
		std::cout << "Before: " << deque << std::endl;
		//sort
		std::cout << "After: " << deque << std::endl;
	}
	catch (std::runtime_error e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
