/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:42:11 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/15 11:51:25 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &my_weapon)
{
    this->_name = name;
    this->_my_weapon = &my_weapon;
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << _my_weapon->getType() << std::endl;
}