#include "MutantStack.hpp"

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

template<class T>
typename MutantStack<T>::riter MutantStack<T>::rbegin()
{
    return std::stack<T>::c.rbegin();
}

template<class T>
typename MutantStack<T>::riter MutantStack<T>::rend()
{
    return std::stack<T>::c.rend();
}