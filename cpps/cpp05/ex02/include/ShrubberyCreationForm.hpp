#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	void execute(Bureaucrat const &executor) const;
	void printTree() const;
};

#endif // ShrubberyCreationForm_HPP
