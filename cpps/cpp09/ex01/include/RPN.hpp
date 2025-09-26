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
	void calculate();
	std::stack<char> _stack;
	void createStack(std::string arg);
	int doOperation(int result, int num, char tok);
	bool isValidToken(char c);
public:
    RPN();
	RPN(std::string arg);
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

	class EmptyConstructoException : public std::exception
	{
		public:
			const char *what() const throw() 
			{
				return "Error: Need something to calculate";
			}
	};
};

#endif // RPN_HPP
