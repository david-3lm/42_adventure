#include "iter.hpp"

void print(int const &a)
{
	std::cout << a << std::endl;
}

void printChar(char const &c)
{
	std::cout << c << std::endl;
}

void doubleVal(int &a)
{
	a = a*2;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	std::string name = "ROMUALDO";


	iter(name.c_str(), name.size(), printChar);
	std::cout << "_______________________" << std::endl;
	iter(arr, 7, print);
	std::cout << "_______________________" << std::endl;
	iter(arr, 7, doubleVal);

	iter(arr, 7, print);

	return 0;
}
