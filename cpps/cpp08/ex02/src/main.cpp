#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
	std::list<int> mstack_list;


    mstack.push(5);
    mstack.push(15);
	mstack_list.push_back(5);
	mstack_list.push_back(15);


    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}
