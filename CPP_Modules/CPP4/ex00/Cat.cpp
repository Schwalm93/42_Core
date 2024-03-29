/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:32:37 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/23 08:53:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "CAT Constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal()
{
	this->_type = copy._type;
	std::cout << "CAT Copy-Constructor called" << std::endl;
}

Cat const &Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
	std::cout << "CAT Assignment-Constructor called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "CAT Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "*Meow! Meow!*" << std::endl;
}