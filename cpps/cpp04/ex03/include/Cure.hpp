#ifndef Cure_HPP
#define Cure_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();                             // Constructor por defecto
    ~Cure();                            // Destructor
    Cure(const Cure &other);            // Constructor copia
    Cure &operator=(const Cure &other); // Operador asignación

    AMateria *clone() const;
    void use(ICharacter& target);
};

#endif // Cure_HPP
