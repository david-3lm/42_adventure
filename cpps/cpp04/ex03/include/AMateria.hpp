#pragma once

#include <iostream>
#include "Character.hpp"

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const & t);
	AMateria(AMateria const &mat);
	~AMateria();

	AMateria & operator=(AMateria const &mat);
	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

