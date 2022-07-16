/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:42:31 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/16 04:58:23 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_H
# define WEAPON_H
#include <iostream>

class Weapon
{
private:
	std::string _type;
public:
	const std::string	&getType() const;
	void				setType(std::string new_type);

	Weapon(std::string name);
	~Weapon();
};


#endif