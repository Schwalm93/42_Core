/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:06:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/13 13:14:12 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>

class Zombie
{
public:

	Zombie(std::string name);
	~Zombie();
	Zombie* newZombie(std::string name);
	void	randomChump(std::string name);
	void announce();

private:

	std::string _name;

};

#endif
