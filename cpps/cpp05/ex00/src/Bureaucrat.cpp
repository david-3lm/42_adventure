#include "Bureaucrat.hpp"

const std::string Bureaucrat::_name = "Doofenshmirtz";

Bureaucrat::Bureaucrat() : _grade(75) {}

Bureaucrat::Bureaucrat(int grade)
{
    try
    {
        if (grade > 150)
            throw GradeTooLowException();
        if (grade < 1)
            throw GradeTooHighException();
        _grade = grade;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    try
    {
        if (_grade <= 1)
            throw GradeTooHighException();
        _grade--;
    }
   catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if (_grade >= 150)
            throw GradeTooLowException();
        _grade++;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
