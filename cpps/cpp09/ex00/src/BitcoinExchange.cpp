#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
	throw BitcoinExchange::EmptyConstructoException();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string file)
{
	std::ifstream fs;

	fs.open(file.c_str());
	if (fs.fail())
	{
		throw BitcoinExchange::ErrorOpeningFileException();
		fs.close();
		return ;
	}
	parseInput(fs);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) 
{
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    if (this != &other) {
    }
    return *this;
}

void BitcoinExchange::parseInput(std::ifstream &file)
{
	std::string date;
	std::string value;
	while (getline(file, date, ','))
	{
		std::cout << date << "\t";
		getline(file, value);
		std::cout << value << std::endl;
		
	}
	
}

bool BitcoinExchange::checkValues(std::string date, std::string value)
{
	// (void)value;
	// boost::regex expr("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	// if (boost::regex_match(date, expr))
	// 	std::cout << "TA BUENO"<< std::endl;
	// return true;
}
