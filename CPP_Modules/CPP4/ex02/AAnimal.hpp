/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:11:32 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:45:55 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ANIMAL_HPP)
#define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal(void);
	AAnimal(AAnimal const &copy);
	AAnimal const &operator=(AAnimal const &rhs);
	virtual ~AAnimal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};



#endif // ANIMAL_HPP



