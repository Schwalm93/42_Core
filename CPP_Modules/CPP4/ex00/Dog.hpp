/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:33:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/23 08:52:18 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(DOG_HPP)
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
private:
    /* data */
public:
    Dog();
    Dog(Dog const &copy);
    Dog const &operator=(Dog const &rhs);
    ~Dog();
    void makeSound() const;
};


#endif // DOG_HPP


