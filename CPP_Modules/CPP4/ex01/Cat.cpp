/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:32:37 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:39:32 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "CAT Constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &copy) : Animal()
{
	this->_type = copy._type;
	this->_brain = new Brain();
	*_brain = *copy._brain;
	std::cout << "CAT Copy-Constructor called" << std::endl;
}

Cat const &Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
	this->_brain = new Brain();
	*_brain = *rhs._brain;
	std::cout << "CAT Assignment-Constructor called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "CAT Destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "*Meow! Meow!*" << std::endl;
}

std::string *Cat::getIdeas()
{
	return (this->_brain->getIdeas());
}

void Cat::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}