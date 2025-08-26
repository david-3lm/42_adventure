#include "Form.hpp"

Form::Form() : _name("DEFAULT_FORM_SIGN_PLS") ,_gradeToSign(20), _gradeToExecute(70) {}

Form::~Form() {}

Form::Form(const Form &other) : _name("DEFAULT_FORM_SIGN_PLS") ,_gradeToSign(other.getGradeToSign()), _gradeToExecute(getGradeToExecute())
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _isSigned = other.getSign();
    }
    return *this;
}



Form::Form(const std::string& name, const int& sign, const int& execute) : _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExecute(execute) {}

Form::Form(const int& toSign, const int& toExecute) : _gradeToSign(toSign), _gradeToExecute(toExecute) {}

bool Form::getSign() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}
