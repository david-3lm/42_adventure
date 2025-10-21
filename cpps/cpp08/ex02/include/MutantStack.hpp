
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

        typedef typename std::stack<T>::container_type::reverse_iterator riter;
        riter rbegin();
        riter rend();
};

#include "../src/MutantStack.tpp"

#endif
