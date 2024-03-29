/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:33:16 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/23 08:53:42 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "DOG Constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal()
{
	this->_type = copy._type;
	std::cout << "DOG Copy-Constructor called" << std::endl;
}

Dog const &Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	std::cout << "DOG Assignment-Constructor called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "DOG Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "*Bark! Bark!*" << std::endl;
}