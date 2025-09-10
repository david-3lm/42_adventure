#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <time.h>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Puntero de tipo A" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "Puntero de tipo B" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "Puntero de tipo C" << std::endl;
}

void identify(Base& p)
{
    try {
        A & a = dynamic_cast<A &>(p);
        (void) a;
        std::cout << "Puntero de tipo A" << std::endl;
    }
    catch(...) {}
    try {
        B & b = dynamic_cast<B &>(p);
        (void) b;
        std::cout << "Puntero de tipo B" << std::endl;
    }
    catch(...) {}
    try {
        C & c = dynamic_cast<C &>(p);
        (void) c;
        std::cout << "Puntero de tipo C" << std::endl;
    }
    catch(...) {}
}

Base* generate()
{
    srand(time(0));
    switch (rand() % 3)
    {
        case 0:
            return new A();
            break;

        case 1:
            return new B();
            break;

        case 2:
            return new C();
            break;

        default:
            break;
    }
    return 0;
}


int main()
{
    Base *ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;
    return 0;
}
