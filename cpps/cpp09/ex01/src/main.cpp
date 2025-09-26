#include "RPN.hpp"

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

bool char_not_valid(char c)
{

	if (std::isdigit(c) || c == ' ' || c == '+' 
		|| c == '-' || c == '*' || c == '/')
		{
			return true;
		}
	return false;
}

bool check_input(std::string input)
{
	int i = 0;
	bool last_was_digit = false;
	while (input[i])
	{
		if (!char_not_valid(input[i]))
		{
			return false;
		}

		if (last_was_digit && isdigit(input[i]))
			return false;
		last_was_digit = isdigit(input[i]);
		i++;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED"Error: Not Enough Arguments" << std::endl;
		return 1;
	}

	if (!check_input(argv[1]))
	{
		std::cerr << RED"Input not valid" << std::endl;
		return 1;
	}

	RPN rpn(argv[1]);
	return 0;
}
