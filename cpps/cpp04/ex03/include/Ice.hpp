#ifndef Ice_HPP
#define Ice_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria 
{
public:
    Ice();                          // Constructor por defecto
    ~Ice();                         // Destructor
    Ice(const Ice &other);  // Constructor copia
    Ice &operator=(const Ice &other); // Operador asignación
    
    AMateria *clone() const;
    void use(ICharacter& target);
};

#endif // Ice_HPP
