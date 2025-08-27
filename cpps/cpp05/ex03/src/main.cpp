#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

void tryForm(AForm &f, Bureaucrat &b)
{
	std::cout << WHITE<<" Vamos a probar este form: " << f.getName() << " con esta persona: " << b << WHITE << std::endl;
	b.signForm(f);
}

int main()
{
    Bureaucrat b(1);

    Bureaucrat b2("Paco", 213);

	ShrubberyCreationForm f("JUAN");
	std::cout << GREEN << std::endl;
    std::cout << b2 << std::endl;
	std::cout << MAGENTA << std::endl;
    std::cout << b << std::endl;
    std::cout << CYAN << std::endl;
    std::cout << f << std::endl;
    std::cout << WHITE << std::endl;

    b.decrementGrade();
    std::cout << BLUE <<"DECREMENTADO: \n\t"<< b << std::endl;

    b2.incrementGrade();
	b.executeForm(f);
	b.signForm(f);
    b.executeForm(f);
	b2.signForm(f);
	b2.executeForm(f);

    return 0;
}
