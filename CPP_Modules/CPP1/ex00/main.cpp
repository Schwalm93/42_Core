/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:05:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/13 13:15:04 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie *my_zombie;

	my_zombie = my_zombie->newZombie("peter");
	my_zombie->announce();
	my_zombie->randomChump("anna");
	delete my_zombie;
	return (0);
}
