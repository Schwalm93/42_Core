/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:11:48 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:46:26 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "Undefined Animal";
	std::cout << "Base Constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy)
{
	this->_type = copy._type;
	std::cout << "Base Copy-Constructor called" << std::endl;
}

AAnimal const &AAnimal::operator=(AAnimal const &rhs)
{
	this->_type = rhs._type;
	std::cout << "Base Assignment-Constructor called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Base Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::makeSound() const
{
	std::cout << "*Undefined Noises*" << std::endl;
}