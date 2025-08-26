#include "Form.hpp"

Form::Form()
{
    // TODO: constructor por defecto
}

Form::~Form()
{
    // TODO: destructor
}

Form::Form(const Form &other)
{
    (void)other;
    // TODO: constructor copia
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        // TODO: operador asignación
    }
    return *this;
}

Form::Form(int toSign, int toExecute) : _gradeToSign(toSign), _gradeToExecute(toExecute) {}
