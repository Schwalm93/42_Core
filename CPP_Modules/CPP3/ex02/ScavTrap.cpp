/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 05:39:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/09 06:21:18 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "default";
	_Hp = 100;
	_Ep = 50;
	_Atk = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_Hp = 100;
	_Ep = 50;
	_Atk = 20;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap()
{
	_name = copy._name;
	_Hp = copy._Hp;
	_Ep = copy._Ep;
	_Atk = copy._Atk;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &assignment)
{
	_name = assignment._name;
	_Hp = assignment._Hp;
	_Ep = assignment._Ep;
	_Atk = assignment._Atk;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "ScavTrap: Destructor called" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << MAGENTA << "ScavTrap is now in Gate keeper mode!" << RESET << std::endl;
}