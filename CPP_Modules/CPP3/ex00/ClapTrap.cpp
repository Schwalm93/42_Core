/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:02:39 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/08 05:37:56 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _Hp(10), _Ep(10), _Atk(0) 
{
	this->_name = "Default";
	std::cout << YELLOW << "Default Constructor: ClapTrap(" << this->_name << ") created!" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Hp(10), _Ep(10), _Atk(0) 
{
	this->_name = name;
	std::cout << YELLOW << "Constructor: ClapTrap(" << this->_name << ") created!" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	this->_Atk = copy._Atk;
	this->_Ep = copy._Ep;
	this->_Hp = copy._Hp;
	this->_name = copy._name;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &assignment)
{
	std::cout << YELLOW << "Assignment Operator: ClapTrap(" << this->_name << ") is now " << assignment._name << "!" << RESET << std::endl;
	this->_Atk = assignment._Atk;
	this->_Ep = assignment._Ep;
	this->_Hp = assignment._Hp;
	this->_name = assignment._name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
 std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_Atk << " points of damage!" << RESET << std::endl;
		this->_Ep--;
	}
	else if (this->_Hp <= 0)
		std::cout << RED << "ClapTrap " << this->_name << " can't attack! Low Hit points." << RESET << std::endl;
	else
		std::cout << RED << "ClapTrap " << this->_name << " can't attack! Low Energie level." << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " got " << amount << " points of damage!" << std::endl;
		this->_Hp = this->_Hp - amount;
	}
	else
		std::cout << "Stop it!" << "ClapTrap " << this->_name << " has already enough....." << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		std::cout << GREEN << "ClapTrap " << this->_name << " heals " << amount << " Hit Points" << RESET << std::endl;
		this->_Ep--;
	}
	else 
		std::cout << GREEN << "ClapTrap " << this->_name << "can't heal." << RESET << std::endl;
}

int ClapTrap::getatkdmg()
{
	return(this->_Atk);
}

int ClapTrap::getep()
{
	return(this->_Ep);
}

int ClapTrap::gethp()
{
	return(this->_Hp);
}