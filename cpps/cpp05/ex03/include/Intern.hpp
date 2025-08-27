#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);

	AForm *makeForm(const std::string &name, const std::string &target);

	class FormNotFound : public std::exception
	{
	public:
        const char* what() const throw();
	};
};

#endif