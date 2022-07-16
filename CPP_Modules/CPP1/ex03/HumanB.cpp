/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:42:18 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/16 04:41:23 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB()
{
}

void    HumanB::attack()
{
	if (this->_my_weapon)
		std::cout << this->_name << " attacks with their " << this->_my_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their Fists" << std::endl;

}

void	HumanB::setWeapon(Weapon & weapon_type)
{
	this->_my_weapon = &weapon_type;
}
