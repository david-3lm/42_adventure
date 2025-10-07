#include <sstream>

int main(int ac, char** av)
{

	std::stringstream data;
	data << av[1];


	int token;

	while (data >> token)
		printf("%d\n", token);

	if (!data.eof())
		printf("cagaste\n");
}