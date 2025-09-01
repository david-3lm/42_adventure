#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b(1);

    Bureaucrat b2;

    Bureaucrat *b3 = new Bureaucrat(45);

    std::cout << b2 << std::endl;
    b2 = b;
    std::cout << b2 << std::endl;

    b.decrementGrade();
    std::cout << b << std::endl;

    b2.incrementGrade();
    std::cout << b2 << std::endl;
    std::cout << *b3 << std::endl;
    delete b3;
    return 0;
}
