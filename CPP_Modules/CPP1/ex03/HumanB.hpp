/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:42:21 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/16 01:05:02 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *_my_weapon = NULL;
	std::string _name;

public:
	void	attack();
	void	setWeapon(Weapon &weapon_type);
    HumanB(std::string name);
    ~HumanB();
};

#endif