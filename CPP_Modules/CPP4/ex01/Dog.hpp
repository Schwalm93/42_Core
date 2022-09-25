/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:33:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:41:12 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(DOG_HPP)
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
private:
    Brain *_brain;
public:
    Dog();
    Dog(Dog const &copy);
    Dog const &operator=(Dog const &rhs);
    ~Dog();
    void makeSound() const;
    std::string *getIdeas();
    void setIdea(int index, std::string idea);
};


#endif // DOG_HPP


