#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

template <typename Container>
class PmergeMe 
{
Container container;
public:
	typedef typename Container::iterator iterator;
    PmergeMe();
	PmergeMe(char **input);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
	void sort();
	typename Container::iterator begin();
	typename Container::iterator end();

};

template <typename Container>
std::ostream &operator<<(std::ostream &os, PmergeMe<Container> &obj);
#include "../src/PmergeMe.cpp"

#endif // PmergeMe_HPP
