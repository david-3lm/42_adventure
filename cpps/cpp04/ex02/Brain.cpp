#include "Brain.hpp"

Brain::Brain()
{
	std::string s;
	for (int i = 0; i < 100; i++)
	{
		s = std::string("Soy una Idea :D");
		this->setIdea(s, i);
	}
}

Brain::~Brain()
{
}

Brain::Brain(const Brain &b)
{
	*this = b;
}

Brain &Brain::operator=(const Brain &b)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->setIdea(b.getIdea(i), i);
	}
	return (*this);
}

std::string Brain::getIdea(int idx) const
{
	return (ideas[idx]);
}

void Brain::setIdea(std::string s, int idx)
{
	ideas[idx] = s; 
}
