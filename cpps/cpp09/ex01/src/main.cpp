#include "RPN.hpp"

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"


int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED"Error: Not Enough Arguments" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(argv[1]);

		std::cout << rpn.getResult() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << WHITE << '\n';
	}
	
	return 0;
}
