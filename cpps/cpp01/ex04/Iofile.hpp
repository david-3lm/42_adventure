#pragma once
#include <iostream>
#include <fstream>

class Iofile
{
private:
	std::string filename;
	std::ifstream instream;
	std::ofstream ostream;
public:
	Iofile(std::string file);
	~Iofile();
	int openFile();
	std::ifstream &getInstream();
	std::ofstream &getOstream();
};


