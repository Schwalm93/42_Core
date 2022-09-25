/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:03:32 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/08 08:14:06 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap Maxwell("Maxwell");
	ClapTrap Tim("Tim");
	ScavTrap Tobias("Tobias");

	Maxwell.attack("Tim");
	Tim.takeDamage(Maxwell.getatkdmg());
	Tim.attack("Maxwell");
	Maxwell.takeDamage(Tim.getatkdmg());
	Maxwell.beRepaired(4);
	Tobias.takeDamage(1);
	Tobias.guardGate();

	ClapTrap nobody;
	nobody = Tim;

	return (0);
}