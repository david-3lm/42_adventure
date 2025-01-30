#include "Replacer.hpp"


Replacer::Replacer(Iofile &handler) : handler(handler) {}

Replacer::~Replacer()
{
}

void Replacer::eraseWrite(std::string s1, std::string s2)
{
	std::string line;

	while (std::getline(handler.getInstream(), line))
	{
		replaceOcc(&line, s1, s2);
		handler.getOstream().write("\n", 1);
	}
}

void Replacer::replaceOcc(std::string *line, std::string s1, std::string s2)
{
	size_t idx = 0;
	std::string newLine = *line;

    while ((idx = newLine.find(s2, idx)) != std::string::npos)
    {
        std::cout << "ENCONTRO en la posición " << idx << std::endl;

        newLine.erase(idx, s2.length());
        newLine.insert(idx, s1);

        idx += s1.length();

    }
	handler.getOstream().write(newLine.c_str(), newLine.length());
}