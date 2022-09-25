/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:11:48 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/23 08:57:38 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "Undefined Animal";
	std::cout << "Base Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	this->_type = copy._type;
	std::cout << "Base Copy-Constructor called" << std::endl;
}

WrongAnimal const &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->_type = rhs._type;
	std::cout << "Base Assignment-Constructor called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Base Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "*Undefined Noises*" << std::endl;
}