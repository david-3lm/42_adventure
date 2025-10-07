#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe() 
{
}

template <typename Container>
PmergeMe<Container>::PmergeMe(char **input)
{
	std::string args_string;
    for (int i = 1; input[i];i++)
	{
        args_string += input[i];
        if(input[i] != NULL)
            args_string += " ";   
    }
    std::istringstream ss(args_string);
    typename Container::value_type n;
    while(ss >> n)
	{
        if (std::find(container.begin(), container.end(), n) != container.end())
            throw std::runtime_error("Duplicate value detected");
       container.push_back(n);
    }
    // if(container.size() != count_word_and_check(args_string))
    //     throw std::runtime_error("Unexpected error");
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() 
{
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other) 
{
    (void)other;
}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other) 
{
    if (this != &other) {
    }
    return *this;
}


template <typename Container>
std::ostream& operator<<(std::ostream &os, PmergeMe<Container> &obj) {
        typename Container::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it) {
            os << *it << " ";
        }
        return os;
}