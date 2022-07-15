/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:05:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/15 05:19:57 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	int n;

	n = 3;
	Zombie *tmp = zombieHorde(n, "Brainden");

	for (size_t i = 0; i < n; i++)
	{
		tmp[i].announce();
	}
	delete[] tmp;
	
	return (0);
}
