#include "Iofile.hpp"


Iofile::Iofile(std::string file)
{
	const std::string ap = file + ".replace";

	filename = file;
	ostream.open(ap.c_str(), std::ofstream::out);
}

Iofile::~Iofile()
{
	if (instream.is_open())
	{
		instream.close();
	}
	if (ostream.is_open())
	{
		ostream.close();
	}
}

int Iofile::openFile()
{
	if (!instream.is_open())
	{
		instream.open(filename.c_str(), std::fstream::in | std::fstream::out);
		if (!instream.is_open())
		{
			std::cout << "Could not open " << filename << std::endl;
			return 0;
		}
		std::cout << "File opened " << filename << std::endl;
		return 1;
	}
	return 0;
}

std::ifstream &Iofile::getInstream()
{
	return instream;
}

std::ofstream &Iofile::getOstream()
{
	return ostream;
}
