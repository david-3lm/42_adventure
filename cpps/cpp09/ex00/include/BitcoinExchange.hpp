#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <exception>
// #include <boost/regex.hpp>

class BitcoinExchange 
{
private:
	std::map<std::string, int> _map;
	void parseInput(std::ifstream &file);
	bool checkValues(std::string date, std::string value);

public:
    BitcoinExchange();
    ~BitcoinExchange();
	BitcoinExchange(const std::string file);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

	class EmptyConstructoException : public std::exception
	{
		public:
			const char *what() const throw() 
			{
				return "Error: Need a file to create BitcoinExchange";
			}
		};
		
	class ErrorOpeningFileException : public std::exception
	{
		public:
		const char *what() const throw() 
		{
			return "Error: Can't open a file";
		}
	};

	class BadInputException : public std::exception
	{
		public:
		const char *what() const throw() 
		{
			return "Error: Bad or corrupted Data";
		}
	};
};

#endif // BitcoinExchange_HPP
