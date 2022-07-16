/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:42:15 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/15 11:51:10 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon *_my_weapon;
	std::string _name;
public:
	void attack();
	HumanA(std::string name, Weapon &my_weapon);
	~HumanA();
};




#endif