#include "RobotomyRequestForm.hpp"

#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy_form", 72, 45) 
{
	_target = "nadie";
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy_form", 72, 45) 
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) 
{
    if (this != &other) 
	{
		this->_target = other.getTarget();
    }
    return *this;
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!this->getSign())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
		std::cout << YELLOW << "BZZZZZ~~~~~~~~~" << std::endl;
		std::srand(std::time(0));
		sleep(1);
		std::cout << YELLOW << "BZZZZZZZZZZZZZZZZZZ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		sleep(1);
		std::cout << YELLOW << "BZZZZZZZZZZZZZZZZZZZZZZZZZZ~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		sleep(1);
		if (std::rand() % 2 == 0)
		{
			std::cout << GREEN"✅ " << _target << " HAS BEEN SUCCESFULLY ROBOTOMIZED ✅" << std::endl;
		}
		else
		{
			std::cout << YELLOW "💣 the drill broke 💣 " << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << WHITE << '\n';
	}
}
