
#include <stack>

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(MutantStack const& other);
        ~MutantStack();
        MutantStack<T> &operator=(MutantStack const& other);

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

template<class T>
MutantStack<T>::MutantStack() {}

template<class T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {}

template<class T>
MutantStack<T>::~MutantStack() {}

template<class T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const &other)
{
	this = other;
    return *this;
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

#endif
