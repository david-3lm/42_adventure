#pragma once

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain& b);

	Brain &operator=(const Brain& b);
	std::string getIdea(int idx) const;
	void setIdea(std::string s, int idx);
};
