#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void execute(Bureaucrat const &executor) const;
};

#endif // PresidentialPardonForm_HPP
