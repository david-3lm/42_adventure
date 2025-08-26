#ifndef Form_HPP
#define Form_HPP

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

    Form(int toSign, int toExecute);
};

#endif // Form_HPP
