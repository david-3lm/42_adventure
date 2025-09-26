#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
	throw BitcoinExchange::EmptyConstructoException();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string file)
{
	std::ifstream fs;
	std::ifstream db;

	db.open("data.csv");
	if (db.fail())
	{
		throw BitcoinExchange::ErrorOpeningFileException();
		db.close();
		return ;
	}
	createMap(db);
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

void BitcoinExchange::calculateValue(std::string date, double q)
{
	double result = 0;

	result = q * _map[date];

	std::cout << date << " => " << q << " = " << result << " $" << std::endl;
}

//TODO: arreglar si solo se mete un valor date | 

void BitcoinExchange::parseInput(std::ifstream &file)
{
	std::string date;
	std::string value;
	bool first_line = true;

	while (getline(file, date, '|'))
	{
		getline(file, value);
		boost::trim_right(date);
		boost::trim_left(value);
		if (first_line)
		{
			first_line = false;
			continue;
		}
		if (!checkValues(date, value))
			throw BitcoinExchange::BadInputException();
		std::cout << date << " => " << _map[date] << std::endl;
		calculateValue(date, std::atof(value.c_str()));
		date = "";
		value = "";
	}
	
}

void BitcoinExchange::createMap(std::ifstream &db)
{
	std::string date;
	std::string value;
	bool first_line = true;

	while (getline(db, date, ','))
	{
		getline(db, value);
		if (first_line)
		{
			first_line = false;
			continue;
		}
		if (!checkMap(date, value))
			throw BitcoinExchange::BadInputException();
		std::cout << date <<"\t"<<value << std::endl;
		_map[date] = std::atof(value.c_str());
	}
	std::cout << "MAPA CREADO" << std::endl;
	std::cout << "UNA PRUEBA \t"<< _map["2022-03-29"] << std::endl;
}

bool BitcoinExchange::checkMap(std::string date, std::string value)
{
	const boost::regex expr("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	if (!boost::regex_match(date.c_str(), expr))
	{
		std::cout << "NO TA BUENO ESTA DB" << std::endl;
		return false;
	}

	if (std::atof(value.c_str()) < 0)
	{
		std::cout << "NO TA BUENO2" << std::endl;
		return false;
	}
	std::cout << "TA BUENO"<< std::endl;
	return true;
}


bool BitcoinExchange::checkValues(std::string date, std::string value)
{
	if (date == "" || value == "")
		return false;

	const boost::regex expr("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	if (!boost::regex_match(date.c_str(), expr))
	{
		std::cout << "NO TA BUENO" << std::endl;
		return false;
	}

	if (std::atof(value.c_str()) < 0 || std::atof(value.c_str()) > 1000)
	{
		std::cout << "NO TA BUENO2" << std::endl;
		return false;
	}
	std::cout << "TA BUENO"<< std::endl;
	return true;
}
