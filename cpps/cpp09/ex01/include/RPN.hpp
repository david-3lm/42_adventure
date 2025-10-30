#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <string>
#include <stack>


class RPN 
{
private:
	std::stack<int> _stack;
	void execute(double(RPN::*f)(double, double));
	double add(double a, double b);
	double minus(double a, double b);
	double mult(double a, double b);
	double div(double a, double b);
public:
    RPN();
	RPN(std::string arg);
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

	double getResult() const;

	class EmptyConstructoException : public std::exception
	{
		public:
			const char *what() const throw() 
			{
				return "Error: Need something to calculate";
			}
	};

	class WrongTokenException : public std::exception
	{
		public:
			const char *what() const throw() 
			{
				return "Error: Wrong Token";
			}
	};

	class NotEnoughNumbersException : public std::exception
	{
		public:
			const char *what() const throw() 
			{
				return "Error: Not enough numbers";
			}
	};

	class NotEnoughTokensException : public std::exception
	{
		public:
			const char *what() const throw() 
			{
				return "Error: Not enough tokens";
			}
	};

	class DivisionZeroException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Error: Zero-Division detected!";
		}
	};
};

#endif // RPN_HPP
