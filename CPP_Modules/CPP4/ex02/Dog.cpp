/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:33:16 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/25 09:48:46 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AAnimal.hpp"

Dog::Dog() : AAnimal()
{
	this->_type = "Dog";
	std::cout << "DOG Constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &copy) : AAnimal()
{
	this->_type = copy._type;
	this->_brain = new Brain();
	*_brain = *copy._brain;
	std::cout << "DOG Copy-Constructor called" << std::endl;
}

Dog const &Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	this->_brain = new Brain();
	*_brain = *rhs._brain;
	std::cout << "DOG Assignment-Constructor called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "DOG Destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "*Bark! Bark!*" << std::endl;
}

std::string *Dog::getIdeas()
{
	return (this->_brain->getIdeas());
}

void Dog::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}