/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:32:37 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/23 09:26:04 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "Cat";
	std::cout << "CAT Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal()
{
	this->_type = copy._type;
	std::cout << "CAT Copy-Constructor called" << std::endl;
}

WrongCat const &WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs._type;
	std::cout << "CAT Assignment-Constructor called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "CAT Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "*Meow! Meow!*" << std::endl;
}