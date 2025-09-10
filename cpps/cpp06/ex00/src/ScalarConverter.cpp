#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void) other;
    return *this;
}

void ScalarConverter::convert(std::string &str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
    {
        char c = str[1];
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return ;
    }
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        float f = std::strtof(str.c_str(), NULL);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        double d = std::strtod(str.c_str(), NULL);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    std::cout << std::fixed << std::setprecision(0);
    char *ptr = 0;
    long l = std::strtol(str.c_str(), &ptr, 10);
	long f = 0;
	if (*ptr == '.')
	{
		f = std::strtol(ptr + 1, &ptr, 10);
		*ptr = 0;
	}
    if (*ptr == '\0')
    {
        if (l < CHAR_MIN || l > CHAR_MAX)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<char>(l)))
            std::cout << "char: non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(l) << std::endl;

        if (l < INT_MIN || l > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(l) << std::endl;
        std::cout << "float: " << static_cast<float>(l) << "." << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(l) << "." << f << std::endl;
        return ;
    }

}