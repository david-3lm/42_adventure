#ifndef Span_HPP
#define Span_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <climits>


class Span 
{
private:
	std::vector<int> _array;
	unsigned int _maxSize;
	unsigned int _size;
public:
    Span();
	Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);


	void addNumber(int nbr);
	void addMultiple(unsigned int count);
	int longestSpan();
	int shortestSpan();
};

#endif // Span_HPP
