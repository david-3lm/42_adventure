#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Empty_Presidential", 25, 5)
{
	this->_target = "nadie";
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) 
{
    if (this != &other) 
	{
		_target = other.getTarget();
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!this->getSign())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
		std::cout << GREEN"✅ " << _target << " HAS BEEN PARDONED BY ALL MIGHTY ZAPHOD BEEBLEBROX ✅" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << WHITE << '\n';
	}
}
