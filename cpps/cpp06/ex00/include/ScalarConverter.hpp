#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <string>


class ScalarConverter 
{
public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static void convert(const std::string &str);
};

#endif // ScalarConverter_HPP
