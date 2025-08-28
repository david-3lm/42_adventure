#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include "Bureaucrat.hpp"
#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

class Bureaucrat;
class AForm 
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
protected:
	std::string _target;
public:
    AForm();
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    AForm(const std::string& name, const int& sign, const int& execute);

    AForm(const int& toSign, const int& toExecute);

    std::string getName()const;
    bool getSign() const;
    int getGradeToSign()const;
    int getGradeToExecute()const;

    void beSigned(const Bureaucrat& b);

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

	class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
	
	std::string getTarget() const;

	virtual void execute(Bureaucrat const &executor) const = 0;

};
std::ostream& operator<<(std::ostream& os, const AForm& b);


#endif // AForm_HPP
