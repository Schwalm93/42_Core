/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:32:50 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/23 09:25:42 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(WRONGCAT_HPP)
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
private:
	/* data */
public:
	WrongCat();
	WrongCat(WrongCat const &copy);
	WrongCat const &operator=(WrongCat const &rhs);
	~WrongCat();
	void makeSound() const;
};

#endif // MACRO



