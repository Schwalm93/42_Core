/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:03:32 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/08 05:35:06 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Maxwell("Maxwell");
	ClapTrap Tim("Tim");

	Maxwell.attack("Tim");
	Tim.takeDamage(Maxwell.getatkdmg());
	Tim.attack("Maxwell");
	Maxwell.takeDamage(Tim.getatkdmg());
	Maxwell.beRepaired(4);

	ClapTrap nobody;
	nobody = Tim;

	return (0);
}