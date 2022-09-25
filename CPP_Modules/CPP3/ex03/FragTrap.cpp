/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:22:22 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/09 06:24:27 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << YELLOW << "Constructor: FragTrap created!" << YELLOW << std::endl; 
	this->_name = "default";
	this->_Hp = 100;
	this->_Ep = 100;
	this->_Atk = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	std::cout << YELLOW << "Constructor: FragTrap created!" << YELLOW << std::endl; 
	this->_name = name;
	this->_Hp = 100;
	this->_Ep = 100;
	this->_Atk = 30;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap()
{	
	this->_name = copy._name;
	this->_Hp = copy._Hp;
	this->_Ep = copy._Ep;
	this->_Atk = copy._Atk;
}

FragTrap& FragTrap::operator=(FragTrap &rhs)
{
	this->_name = rhs._name;
	this->_Hp = rhs._Hp;
	this->_Ep = rhs._Ep;
	this->_Atk = rhs._Atk;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "FragTrap: destructor called!" << YELLOW << std::endl; 
}

void FragTrap::highFivesGuys(void)
{
	std::cout << MAGENTA << "Fragtrap " + this->_name << ": High five guys!" << RESET << std::endl;
}
