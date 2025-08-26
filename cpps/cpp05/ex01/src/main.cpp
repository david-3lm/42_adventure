#include "Bureaucrat.hpp"

//TODO hacer un main relevante
int main()
{
    Bureaucrat b(1);

    Bureaucrat b2("Paco", 213);

    std::cout << b2 << std::endl;
    b2 = b;
    std::cout << b2 << std::endl;

    b.decrementGrade();
    std::cout << b << std::endl;

    b2.incrementGrade();
    std::cout << b2 << std::endl;
    return 0;
}
