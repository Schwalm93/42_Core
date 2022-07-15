/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:06:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/15 04:56:37 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>

class Zombie
{
public:

	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();

private:

	std::string _name;

};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif
