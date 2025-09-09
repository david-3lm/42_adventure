#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return 0;

	ScalarConverter s;

	std::string argum(argv[1]);

	s.convert(argum);
	
	return 0;
}
