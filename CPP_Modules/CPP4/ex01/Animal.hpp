/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:11:32 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:41:31 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ANIMAL_HPP)
#define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
	std::string _type;
public:
	Animal(void);
	Animal(Animal const &copy);
	Animal const &operator=(Animal const &rhs);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};



#endif // ANIMAL_HPP



