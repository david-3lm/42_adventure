#ifndef ICharacter_HPP
#define ICharacter_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{

public:
    virtual ~ICharacter();

    virtual      std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
	public:
		Character();
		Character(std::string name);
		Character(Character const &src);
		virtual	~Character();

		Character &			operator=(Character const &rSym);
		virtual std::string const &	getName() const;

		virtual void    equip(AMateria *m);
		virtual void    unequip(int idx);
		virtual void    use(int idx, ICharacter &target);
	private:
		int idxTotal;
		std::string name;
		AMateria *inventory[4];
};

#endif // ICharacter_HPP
