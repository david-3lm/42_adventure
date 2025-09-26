#include "RPN.hpp"

RPN::RPN() 
{
	throw RPN::EmptyConstructoException();
}

RPN::~RPN() {}

RPN::RPN(std::string arg)
{
	createStack(arg);
	calculate();
}

RPN::RPN(const RPN &other) 
{
    (void)other;
}

RPN &RPN::operator=(const RPN &other) 
{
    if (this != &other) {
    }
    return *this;
}

void RPN::calculate()
{
	int result = std::atoi(&_stack.top());
	std::stack<int> num;
	char tok;

	_stack.pop();

	while (_stack.size() > 0)
	{
		tok = _stack.top();
		_stack.pop();
		if (isValidToken(tok))
		{
			result = doOperation(result, num.top(), tok);
			num.pop();
		}
		else if (isdigit(tok))
		{
			num.push(std::atoi(&tok));
		}
	}
	std::cout << result << std::endl;
}

int RPN::doOperation(int result, int num, char tok)
{
	switch (tok)
	{
	case '+':
		return result + num;
	case '-':
		return result - num;
	case '*':
		return result * num;
	case '/':
		return result / num;
	default:
		break;
	}
	return result;
}

bool RPN::isValidToken(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			return true;
		}
	return false;
}

void RPN::createStack(std::string arg)
{
	std::string c;
	std::stringstream ss(arg);
	std::stack<char> aux;

	while (getline(ss, c, ' '))
	{
		aux.push(*(c.c_str()));
	}
	int size = aux.size();
	for (int i = 0; i < size; i++)
	{
		_stack.push(aux.top());
		aux.pop();
	}
}
