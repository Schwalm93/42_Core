/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:16:37 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/15 05:19:34 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int n, std::string name)
{
	Zombie *zombies = new Zombie[n];

	for (size_t i = 0; i < n; i++)
	{
		zombies[i].setname(name);
	}
	return (zombies);
}