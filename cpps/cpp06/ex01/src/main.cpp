#include <iostream>
#include <ostream>

#include "Serializer.hpp"
#include "../include/Serializer.hpp"


int main()
{
    Data data;
    data.value = 33;
    data.name = "Viva Fernando Alonso";

    std::cout << "OG Data: \n - " << data.value << "\n - " <<  data.name << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Raw: " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);
    std::cout << "DESERIALIZED Data: \n - " << ptr->value << "\n - " <<  ptr->name << std::endl;

}
