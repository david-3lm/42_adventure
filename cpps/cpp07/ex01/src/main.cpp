#include "iter.hpp"

void print(int const &a)
{
	std::cout << a << std::endl;
}

void add(int const &a)
{
	a = a+1;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};

	iter(arr, 7, print);


	iter(arr, 7, add);

	iter(arr, 7, print);

	return 0;
}
