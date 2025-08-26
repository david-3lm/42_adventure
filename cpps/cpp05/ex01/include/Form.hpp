#ifndef Form_HPP
#define Form_HPP
#include <iostream>

//TODO beSigned y error handling
class Form 
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    Form();
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);

    Form(const std::string& name, const int& sign, const int& execute);

    Form(const int& toSign, const int& toExecute);

    std::string getName()const;
    bool getSign() const;
    int getGradeToSign()const;
    int getGradeToExecute()const;


};

#endif // Form_HPP
