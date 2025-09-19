#include "Span.hpp"

Span::Span() : _maxSize(0), _size(0){}

Span::Span(unsigned int N) : _maxSize(N), _size(0){}

Span::~Span() {}

Span::Span(const Span &other) 
{
    this->_array = other._array;
	this->_maxSize = other._maxSize;
	this->_size = other._size;
}

Span &Span::operator=(const Span &other) 
{
    if (this != &other)
	{
		this->_array = other._array;
		this->_maxSize = other._maxSize;
		this->_size = other._size;
    }
    return *this;
}

void Span::addNumber(int nbr)
{
	if (this->_size >= this->_maxSize)
	{
		//TODO: exception

	}
	this->_array.push_back(nbr);
	this->_size++;
}

void Span::addMultiple(unsigned int count)
{
	if (this->_size + count > this->_maxSize)
	{
		//TODO: exception
	}

	int n;
	for (size_t i = 0; i < count; i++)
	{
		n = rand() % this->_maxSize + 1;
		this->addNumber(n);
	}
	
}

int Span::longestSpan()
{
	//TODO: exceptions

	int max = *std::max_element(this->_array.begin(), this->_array.end());
	int min = *std::min_element(this->_array.begin(), this->_array.end());
	return max - min;
}

int Span::shortestSpan()
{
	//TODO: exceptions

	std::sort(this->_array.begin(), this->_array.end());

	long long minDiff = LLONG_MAX;
	for (size_t i = 1; i < this->_array.size(); i++)
	{
		long long diff = this->_array[i] - this->_array[i - 1];
		if (diff < minDiff)
			minDiff = diff;
		if (diff == 0)
			return 0;
	}
	return minDiff;
}
