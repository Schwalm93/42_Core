/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:11:48 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:44:04 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Undefined Animal";
	std::cout << "Base Constructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	this->_type = copy._type;
	std::cout << "Base Copy-Constructor called" << std::endl;
}

Animal const &Animal::operator=(Animal const &rhs)
{
	this->_type = rhs._type;
	std::cout << "Base Assignment-Constructor called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Base Destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "*Undefined Noises*" << std::endl;
}