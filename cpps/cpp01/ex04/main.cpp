#include <iostream>
#include <fstream>
#include "Iofile.hpp"
#include "Replacer.hpp"

void	replaceInFile(const std::string file, std::string s1, std::string s2)
{
	Iofile ioFile(file);
	Replacer replacer(ioFile);

	if (!ioFile.openFile())
		return ;
	replacer.eraseWrite(s1, s2);
}

int main(int argc, char const *argv[])
{
	if (argc != 4)
		return 1;
	replaceInFile(argv[1], argv[2], argv[3]);
	return 0;
}