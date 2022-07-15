/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:06:36 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/15 05:10:43 by cschwalm         ###   ########.fr       */
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
	void setname(std::string new_name);

private:

	std::string _name;

};

Zombie* zombieHorde(int N, std::string name);

#endif
