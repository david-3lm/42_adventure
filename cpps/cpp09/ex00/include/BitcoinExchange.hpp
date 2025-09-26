#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <exception>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>

class BitcoinExchange 
{
private:
	std::map<std::string, double> _map;
	void parseInput(std::ifstream &file);
	void createMap(std::ifstream &db);
	bool checkMap(std::string date, std::string value);
	bool checkValues(std::string date, std::string value);
	void calculateValue(std::string date, double q);

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
			return "Error: Bad Input :(";
		}
	};

	class BadDateException : public std::exception
	{
		public:
		const char *what() const throw() 
		{
			return "Error: Bad or corrupted Date";
		}
	};

	class BadValueException : public std::exception
	{
		public:
		const char *what() const throw() 
		{
			return "Error: Bad Value, {integer between 0-1000}";
		}
	};
};

#endif // BitcoinExchange_HPP
