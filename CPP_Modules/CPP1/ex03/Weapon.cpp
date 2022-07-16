/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:42:28 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/16 04:49:59 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->setType(name);
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}

const std::string &Weapon::getType() const
{
	return (this->_type);
}
