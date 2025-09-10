#ifndef Serializer_HPP
#define Serializer_HPP
#include <stdint.h>
#include <string>

struct Data {
    int value;
    std::string name;
};

class Serializer 
{
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // Serializer_HPP
