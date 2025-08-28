#include "AForm.hpp"

AForm::AForm() : _name("DEFAULT_AFORM_SIGN_PLS") ,_gradeToSign(20), _gradeToExecute(70) {}

AForm::~AForm() 
{
	
}

AForm::AForm(const AForm &other) : _name("DEFAULT_AFORM_SIGN_PLS") ,_gradeToSign(other.getGradeToSign()), _gradeToExecute(getGradeToExecute())
{
    *this = other;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _isSigned = other.getSign();
    }
    return *this;
}

AForm::AForm(const std::string& name, const int& sign, const int& execute) : _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExecute(execute) {}

AForm::AForm(const int& toSign, const int& toExecute) : _gradeToSign(toSign), _gradeToExecute(toExecute) {}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSign() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    try
    {
        if (b.getGrade() > _gradeToSign)
            throw AForm::GradeTooLowException();
        _isSigned = true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "⚠️ ⚠️ AFORM said: DEMASIADO ALTOOO ⚠️ ⚠️";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "⚠️ ⚠️ AFORM said: DEMASIADO BAJOOOOOOOOO ⚠️ ⚠️";
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return " AFORM said: ESTE FORMULARIO NO ESTÁ FIRMADO";
}

std::ostream &operator<<(std::ostream &os, const AForm &t)
{
    os << "AForm: <" << t.getName() << "> \n\t - Grade to needed sign: " << t.getGradeToSign() << "\n\t - Grade to needed execute:" << t.getGradeToExecute();
    return os;
}

std::string AForm::getTarget() const
{
	return _target;
}
