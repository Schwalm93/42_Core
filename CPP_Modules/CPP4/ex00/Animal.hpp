#if !defined(ANIMAL_HPP)
#define ANIMAL_HPP

#include <iostream>

class Animal
{
private:
    std::string type;
public:
    Animal(void);
    // Animal();
    Animal(Animal &copy);
    Animal &operator=(Animal &rhs);
    ~Animal();
};

#endif // ANIMAL_HPP
