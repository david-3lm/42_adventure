#ifndef Base_HPP
#define Base_HPP

class Base 
{
public:
    virtual ~Base();
    Base *generate(void);
    void identify(Base *p);
    void identify(Base& p);
};

#endif // Base_HPP
