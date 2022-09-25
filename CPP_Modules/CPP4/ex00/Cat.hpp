/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:32:50 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/23 08:52:21 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CAT_HPP)
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
private:
	/* data */
public:
	Cat();
	Cat(Cat const &copy);
	Cat const &operator=(Cat const &rhs);
	~Cat();
	void makeSound() const;
};

#endif // MACRO



