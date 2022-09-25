/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:11:32 by cschwalm          #+#    #+#             */
/*   Updated: 2022/09/23 09:26:20 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(WRONGANIMAL_HPP)
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &copy);
	WrongAnimal const &operator=(WrongAnimal const &rhs);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};



#endif // ANIMAL_HPP



