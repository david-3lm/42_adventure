#pragma once
#include "Iofile.hpp"

class Replacer
{
private:
	Iofile &handler;
	void replaceOcc(std::string *line, std::string s1, std::string s2);
public:
	Replacer(Iofile &handler);
	~Replacer();

	void eraseWrite(std::string s1, std::string s2);
};
