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
	if (!createMap(db)) return;
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
    if (this != &other)
	{
		*this = other;
    }
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    if (this != &other)
	{
		this->_map = other._map;
    }
    return *this;
}

void BitcoinExchange::calculateValue(std::string date, double q)
{
	double result = 0;

	result = q * _map[date];

	std::cout << date << " => " << q << " = " << result << std::endl;
}


void BitcoinExchange::parseInput(std::ifstream &file)
{
	std::string date;
	std::string value;
	std::string line;

	getline(file, line);
	if (line != "date | value")
		throw BitcoinExchange::ErrorOpeningFileException();

	while (getline(file, line))
	{
		try
		{
			std::istringstream ss(line);
			getline(ss, date, '|');
			getline(ss, value, '|');

			boost::trim_right(date);
			boost::trim_left(value);

			double dValue;
			std::istringstream valueStream(value);
			if (!(valueStream >> dValue))
				throw BitcoinExchange::BadValueException();
			checkValues(date,dValue);
			calculateValue(date, dValue);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue;
		}
	}
	
}

bool BitcoinExchange::createMap(std::ifstream &file)
{
	std::string date;
	std::string value;
	std::string line;

	getline(file, line);
	try
	{	
		if (line != "date,exchange_rate")
			throw BitcoinExchange::ErrorOpeningFileException();

		while (getline(file, line))
		{
				std::istringstream ss(line);
				getline(ss, date, ',');
				getline(ss, value, ',');

				boost::trim_right(date);
				boost::trim_left(value);

				double dValue;
				std::istringstream valueStream(value);
				if (!(valueStream >> dValue))
					throw BitcoinExchange::BadValueException();

				checkMap(date, dValue);
				_map[date] = dValue;
		}
		return true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return false;

	}
}

bool BitcoinExchange::checkMap(std::string date, double value)
{
	if (!validateDate(date))
	{
		return false;
	}

	if (value < 0)
	{
		return false;
	}
	return true;
}


bool BitcoinExchange::checkValues(std::string date, double value)
{
	if (date == "")
		return false;

	if (!validateDate(date))
	{
		throw BitcoinExchange::BadDateException();
	}

	if (value < 0 || value > 1000)
	{
		throw BitcoinExchange::BadValueException();
	}
	return true;
}

bool BitcoinExchange::validateDate(std::string const &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date[i]) == 0)
			return (false);
	}

	if (date[5] == '0' && date[6] == '0') 
		return (false);
	if ((date[5] == '1' && date[6] > '2') || date[5] > '1')
		return (false);

	if (date[8] == '0' && date[9] == '0')
		return (false);
	if ((date[8] == '3' && date[9] > '1') || date[8] > '3')
		return (false);
	
	return (true);
}
