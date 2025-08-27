#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other); 
    Bureaucrat &operator=(const Bureaucrat &other);

    Bureaucrat(int grade);
    Bureaucrat(const std::string& name, int grade);

    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

	void signForm(AForm &f) const;
	void executeForm(AForm &f) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

	class FormSignedException : public std::exception {
	public:
        const char* what() const throw();
	};

	class BadExecutionException : public std::exception {
	public:
        const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif // Bureaucrat_HPP
