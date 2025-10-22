#include "RPN.hpp"


RPN::RPN()
{
	throw RPN::EmptyConstructoException();
}

RPN::~RPN() {}

RPN::RPN(std::string arg)
{
	std::stringstream ss(arg);
	std::string tok;
	int n;

	while (getline(ss, tok, ' '))
	{
		if ((tok.length() == 1 && isdigit(tok[0])))
		{
			std::stringstream(tok) >> n;
			_stack.push(n);
		}
		else if (tok == "+")
			execute(&RPN::add);
		else if (tok == "-")
			execute(&RPN::minus);
		else if (tok == "*")
			execute(&RPN::mult);
		else if (tok == "/")
			execute(&RPN::div);
		else
			throw RPN::WrongTokenException();

	}	
}

void RPN::execute(double (RPN::*f)(double,double))
{
	double a;
	double b;

	if (_stack.size() < 2)
		throw RPN::EmptyConstructoException();
	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	_stack.push((this->*f)(a, b));
}

double RPN::getResult() const
{
	if (_stack.empty())
		throw RPN::NotEnoughNumbersException();
	else if (_stack.size() > 1)
		throw RPN::NotEnoughTokensException();
	return (_stack.top());
	
}

double RPN::add(double a, double b)
{
	return (b + a);
}

double RPN::minus(double a, double b)
{
	return (b - a);
}

double RPN::mult(double a, double b)
{
	return (b * a);
}

double RPN::div(double a, double b)
{
	return (b / a);
}

RPN::RPN(const RPN &other) 
{
    if (this != &other)
		*this = other;
}

RPN &RPN::operator=(const RPN &other) 
{
    if (this != &other)
		this->_stack = other._stack;
    return *this;
}


