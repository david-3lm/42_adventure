#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	Harl h;
	if (argc != 2)
		return 1;
	
	h.complaing(argv[1]);
	return 0;
}
