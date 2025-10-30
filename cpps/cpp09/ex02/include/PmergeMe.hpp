#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>

class PmergeMe
{
private:
	std::deque<int> _deq;
	std::vector<int> _vec;
	void mergeInsertionDeque(std::deque<int> &deque);
	void mergeInsetionVector();
public:
    PmergeMe();
	PmergeMe(char **input);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
	void sort();
	std::deque<int> &getDeque();
	std::vector<int> &getVector();
};

std::ostream &operator<<(std::ostream &os, PmergeMe &obj);

#endif // PmergeMe_HPP
