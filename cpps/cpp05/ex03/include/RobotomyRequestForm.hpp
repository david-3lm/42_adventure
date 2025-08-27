#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void execute(Bureaucrat const &executor) const;
};

#endif // RobotomyRequestForm_HPP
