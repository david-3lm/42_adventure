#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			while (*argv[i])
			{
				std::cout << (char)toupper(*argv[i]);
				argv[i]++;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
