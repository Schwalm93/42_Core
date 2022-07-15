/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:06:48 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/15 05:11:03 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


void Zombie::announce()
{
	std::cout << this->_name << ":" << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setname(std::string new_name)
{
	this->_name = new_name;
}

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " destroyed" << std::endl;
}
