#include "Bureaucrat.hpp"

#define DEF_NAME "Doofenshmirtz"
// const std::string Bureaucrat::_name = "Doofenshmirtz";

Bureaucrat::Bureaucrat() : _name(DEF_NAME), _grade(75) {}

Bureaucrat::Bureaucrat(int grade) : _name(DEF_NAME)
{
    try
    {
        if (grade > 150)
        {
           _grade = 150;
            throw GradeTooLowException();
        }
        if (grade < 1)
        {
            _grade = 1;
            throw GradeTooHighException();
        }
        _grade = grade;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    try
    {
        if (grade > 150)
        {
            _grade = 150;
            throw GradeTooLowException();
        }
        if (grade < 1)
        {
            _grade = 1;
            throw GradeTooHighException();
        }
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

void Bureaucrat::signForm(AForm &f) const
{
	try
	{
		if (f.getSign())
			throw Bureaucrat::FormSignedException();
		f.beSigned(*this);
		if ((f.getGradeToSign() < _grade))
			throw AForm::GradeTooLowException();
		std::cout << GREEN << _name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << _name << " couldn't sign " << f.getName() << " because " << e.what() << WHITE << '\n';
	}
	
}

void Bureaucrat::executeForm(AForm &f) const
{
	try
	{
		std::cout << GREEN << _name << " executed " << f.getName() << std::endl;
		f.execute(*this);
		if (!f.getSign() || (f.getGradeToExecute() < _grade))
			throw Bureaucrat::BadExecutionException();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << WHITE << '\n';
	}
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "⚠️ ⚠️ TE PASASTE DE ALTOOOOO BUROCRATA ⚠️ ⚠️";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "⚠️ ⚠️ TE PASASTE DE BAJOOOO BUROCRATA ⚠️ ⚠️";
}

const char *Bureaucrat::FormSignedException::what() const throw()
{
    return "⚠️ ⚠️ Formulario firmado ya ⚠️ ⚠️";
}

const char *Bureaucrat::BadExecutionException::what() const throw()
{
    return "⚠️ ⚠️ NO SE PUEDE EJECUTAR ⚠️ ⚠️";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
