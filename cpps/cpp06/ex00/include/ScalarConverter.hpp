#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <string>
#include <iomanip>



class ScalarConverter 
{
public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static void convert(std::string &str);
};

#endif // ScalarConverter_HPP
